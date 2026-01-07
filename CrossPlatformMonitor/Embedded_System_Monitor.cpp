#include "Embedded_System_Monitor.h"

void LogError(const std::string& component, const std::string& message) {
    std::cerr << "[ERROR][" << component << "] " << message;
#ifdef _WIN32
    std::cerr << " | Windows Error Code: " << GetLastError();
#endif
    std::cerr << std::endl;
}

CPU::CPU() {
#ifdef _WIN32
    FILETIME idletime, kerneltime, usertime;
    if (GetSystemTimes(&idletime, &kerneltime, &usertime)) {
        idle = ((ULONGLONG)idletime.dwHighDateTime << 32) | idletime.dwLowDateTime;
        kernnel = ((ULONGLONG)kerneltime.dwHighDateTime << 32) | kerneltime.dwLowDateTime;
        user = ((ULONGLONG)usertime.dwHighDateTime << 32) | usertime.dwLowDateTime;
    } else {
        std::cerr << "[CRITICAL ERROR]: System API failure during CPU init. Code: " << GetLastError() << std::endl;
        exit(1); 
    }
#else
    idle = kernnel = user = 0;
#endif
}

ULONGLONG CPU::getIdelTime(){
    return idle;
}

ULONGLONG CPU::getKernelTime(){
    return kernnel;
}
ULONGLONG CPU::getUserTime(){
    return user;
}
ULONGLONG CPU::getIdelTimeTwo(){
    return idleSecond;
}
ULONGLONG CPU::getKernelTimeTwo(){
    return kernnelSecond;
}
ULONGLONG CPU::getUserTimeTwo(){
    return userSecond;
}
/* float CPU::CPUUsage(){ //CPU% = 100 × (ΔKernel + ΔUser − ΔIdle) / (ΔKernel + ΔUser) Δ=2-1
    ULONGLONG Dk = (getKernelTimeTwo() - getKernelTime());
    ULONGLONG Di = (getIdelTimeTwo() - getIdelTime());
    ULONGLONG Du = (getUserTimeTwo()-getUserTime());
    if (Dk + Du == 0){
        return 0.0f;
    } 
    if ((Dk + Du < Di)){
        return 0.0f;
    }
    return 100.0f * ((Dk + Du) - Di) / (Dk + Du);

} */
float CPU::CPUUsage(){
#ifdef _WIN32
    FILETIME idletime, kerneltime, usertime;
    if(!GetSystemTimes(&idletime, &kerneltime, &usertime)){
        return 0.0f;
    }
    ULONGLONG nowIdle = ((ULONGLONG)idletime.dwHighDateTime << 32) | idletime.dwLowDateTime;
    ULONGLONG nowKernel = ((ULONGLONG)kerneltime.dwHighDateTime << 32) | kerneltime.dwLowDateTime;
    ULONGLONG nowUser = ((ULONGLONG)usertime.dwHighDateTime << 32) | usertime.dwLowDateTime;
    ULONGLONG Dk = nowKernel - kernnel;
    ULONGLONG Du = nowUser - user;
    ULONGLONG Di = nowIdle - idle;
    idle = nowIdle;
    kernnel = nowKernel;
    user = nowUser;
    ULONGLONG totalSystemTime = Dk + Du;
    if(totalSystemTime == 0){
        return 0.0f;
    }
    float usage = 100.0f * (totalSystemTime - Di) / totalSystemTime;
    if(usage < 0.0f){
        return 0.0f;
    }
    if(usage > 100.0f){
        return 100.0f;
    }
    return usage;
#else
    long double a[4], b[4];
    std::ifstream file("/proc/stat");
    std::string ignore;
    file >> ignore >> a[0] >> a[1] >> a[2] >> a[3];
    file.close();

    static long double prevTotal = 0;
    static long double prevIdle = 0;
    long double idle = a[3];
    long double total = a[0] + a[1] + a[2] + a[3];
    long double totalDiff = total - prevTotal;
    long double idleDiff = idle - prevIdle;
    prevTotal = total;
    prevIdle = idle;

    return (totalDiff > 0) ? 100.0f * (1.0f - (idleDiff / totalDiff)) : 0.0f;
#endif
}

void CPU::flipflip(){
    fliper = !fliper;
}
bool CPU::getfliper(){
    return fliper;
}

void CPU::updateTimes() {
    FILETIME idletime, kerneltime, usertime;
    if (GetSystemTimes(&idletime, &kerneltime, &usertime)) {
        if (getfliper()) {
            idle = ((ULONGLONG)idletime.dwHighDateTime << 32) | idletime.dwLowDateTime;
            kernnel = ((ULONGLONG)kerneltime.dwHighDateTime << 32) | kerneltime.dwLowDateTime;
            user = ((ULONGLONG)usertime.dwHighDateTime << 32) | usertime.dwLowDateTime;
        } else {
            idleSecond = ((ULONGLONG)idletime.dwHighDateTime << 32) | idletime.dwLowDateTime;
            kernnelSecond = ((ULONGLONG)kerneltime.dwHighDateTime << 32) | kerneltime.dwLowDateTime;
            userSecond = ((ULONGLONG)usertime.dwHighDateTime << 32) | usertime.dwLowDateTime;
        }
        flipflip();
    } else {
        LogError("CPU_Update", "Failed to retrieve system times during loop.");
    }
}

Memory::Memory(){
    getmemoryLod();
}
float Memory::getmemoryLod(){
#ifdef _WIN32
    MEMORYSTATUSEX memoryjunk;
    memoryjunk.dwLength = sizeof(memoryjunk);
    if (!GlobalMemoryStatusEx(&memoryjunk)) {
        LogError("MemoryQuery", "GlobalMemoryStatusEx failed.");
        return memorystuf;
    }
    memorystuf = (float)memoryjunk.dwMemoryLoad;
    return memorystuf;
#else
    struct sysinfo memInfo;
    sysinfo(&memInfo);
    long long totalPhysMem = memInfo.totalram;
    totalPhysMem *= memInfo.mem_unit;
    long long physMemUsed = memInfo.totalram - memInfo.freeram;
    physMemUsed *= memInfo.mem_unit;
    
    return (float)((physMemUsed * 100) / totalPhysMem);
#endif
}

bool Memory::critLod(){
    return (getmemoryLod() >= 95.0f);
}

disc::disc(){
    getfreeDGB();
}

double disc::getfreeDGB(){
    char cwd[256];
    if (GET_CWD(cwd, sizeof(cwd)) == NULL){
        return -1.0;
    }
#ifdef _WIN32
    ULARGE_INTEGER totalFreeBytes;
    // Passing NULL to GetDiskFreeSpaceEx uses the current disk
    if(!GetDiskFreeSpaceExA(cwd, nullptr, nullptr, &totalFreeBytes)) {
        LogError("DiskAPI", "Failed to query disk space for " + std::string(cwd));
        return -1.0;
    }
    freeDGB = static_cast<double>(totalFreeBytes.QuadPart) / 1073741824.0;
    return freeDGB;
#else
    struct statvfs fiData;
    if((statvfs("/", &fiData)) < 0 ) {
        std::cerr << "[ERROR][DiskAPI] statvfs failed for root." << std::endl;
        return -1.0;
    }
    double freeBytes = (double)fiData.f_bfree * fiData.f_frsize;
    return freeBytes / 1073741824.0;
#endif
}

std::string uptime::returnUPt(){
    ULONGLONG uptime_ms;
#ifdef _WIN32
    uptime_ms = GetTickCount64();
    seconds = uptime_ms / 1000;
#else
    struct sysinfo info;
    if (sysinfo(&info) != 0){
        return "0s";
    }
    seconds = info.uptime;
#endif

    std::string output;
    
    if (seconds > 60){
        minutes = seconds / 60;
        seconds = seconds % 60;
        output = std::to_string(seconds) + " seconds.";
    } else {
        return std::to_string(seconds) + " seconds.";
    }
    if (minutes > 60){
        hours = minutes / 60;
        minutes = minutes % 60;
        output = std::to_string(minutes) + " minutes." + output;
    } else {
        return std::to_string(minutes) + " minutes." + output;
    }
    if (hours > 24){
        days = hours / 24;
        hours = hours % 24;
        output = std::to_string(hours) + " hours." + output;
    } else {
        return std::to_string(hours) + " hours." + output;
    }
    if (days > 30){
        months = days / 30;
        days = days % 30;
        output = std::to_string(months) + " months." + std::to_string(days) + " days." + output;
    } else {
        output = std::to_string(days) + " days." + output;
    }
    return output;
}

std::string uptime::getOSName(){
    #ifdef _WIN32
        return "Windows";
    #elif __APPLE__
        return "macOS";
    #elif __linux__
        return "Linux";
    #else
        return "Unknown OS";
    #endif
}