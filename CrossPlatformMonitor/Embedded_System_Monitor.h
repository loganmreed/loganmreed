#ifndef ESM_H
#define ESM_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#ifdef _WIN32
    #include <windows.h>
    #include <direct.h>
    #define GET_CWD _getcwd
#else
    #include <unistd.h>
    #include <sys/sysinfo.h>
    #include <sys/statvfs.h>
    #include <fstream>
    #define GET_CWD getcwd
#endif

class CPU{
    private: 
        ULONGLONG idle;
        ULONGLONG kernnel;
        ULONGLONG user;
        ULONGLONG idleSecond;
        ULONGLONG kernnelSecond;
        ULONGLONG userSecond;
        bool fliper; // 0=first 1= secodn
    public:
        CPU();
        ULONGLONG getIdelTime();
        ULONGLONG getKernelTime();
        ULONGLONG getUserTime();
        ULONGLONG getIdelTimeTwo();
        ULONGLONG getKernelTimeTwo();
        ULONGLONG getUserTimeTwo();
        void flipflip();
        bool getfliper();
        float CPUUsage(); //CPU% = 100 × (ΔKernel + ΔUser − ΔIdle) / (ΔKernel + ΔUser) Δ=2-1
        void updateTimes();
};

class Memory{
    private:
        DWORD memorystuf;
    public:
        Memory();
        float getmemoryLod();
        bool critLod();
        //flag

};

class disc{
    private:
        double freeDGB;
    public:
        disc();
        double getfreeDGB();
};

class uptime{
    private:
        ULONGLONG months;
        ULONGLONG seconds;
        ULONGLONG minutes;
        ULONGLONG hours;
        ULONGLONG days;
    public:
        std::string returnUPt();
        std::string getOSName();
};

#endif