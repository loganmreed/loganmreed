#include "Embedded_System_Monitor.h"

int main() {
    CPU myCPU;
    Memory myMem;
    disc myDisc;
    uptime myUptime;
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif
    std::cout << "\033[2J" << std::fixed << std::setprecision(2);
    while (true) {
        std::cout << "\033[H";
        float cpuUsage = myCPU.CPUUsage();
        float memLoad = myMem.getmemoryLod();
        double freeDisk = myDisc.getfreeDGB();
        std::cout << "========================================" << std::endl;
        std::cout << "       EMBEDDED SYSTEM MONITOR          " << std::endl;
        std::cout << "       OS: " << myUptime.getOSName() << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "CPU Utilization:    " << cpuUsage << "%     " << std::endl;
        std::cout << "Memory Load:        " << memLoad << "%     " << std::endl;
        if (myMem.critLod()) {
            std::cout << "\033[1;31m[!] WARNING: HIGH MEMORY [!]\033[0m   " << std::endl;
        } else {
            std::cout << "                            " << std::endl;
        }
        std::cout << "Free Disk Space:    " << freeDisk << " GB    " << std::endl;
        std::cout << "System Uptime:      " << myUptime.returnUPt() << "          " << std::endl;
        std::cout << "========================================" << std::endl;
#ifdef _WIN32
        Sleep(500);
#else
        usleep(500000);
#endif
    }
    return 0;
}