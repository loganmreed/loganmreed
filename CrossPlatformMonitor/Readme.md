## Cross-Platform Embedded System Monitor

A lightweight, cross-platform C++ system monitoring utility designed for real-time tracking of hardware resources. It provides a terminal-based dashboard for CPU utilization, memory load, disk availability, and system uptime.


# Features
- Cross-Platform Support: Works on both Windows (Win32 API) and Linux (procfs/sysinfo).
- Real-time CPU Tracking: Calculates CPU usage percentage based on delta time between system ticks.
- Memory Monitoring: Tracks physical memory load and includes a built-in "Critical Load" warning (triggered at 95%).
- Disk Analytics: Reports free disk space in Gigabytes (GB) for the current working directory.
- Uptime Formatting: Converts raw system ticks into a human-readable format (Months, Days, Hours, Minutes, Seconds).
- Live Dashboard: Uses ANSI escape codes to provide a flicker-free, refreshing terminal UI.

# Project Structure
* CPU: This class handles system time snapshots and calculates utilization percentage.
```text
+----------------------------------------+
|                 CPU                    |
+----------------------------------------+
| - idle: ULONGLONG                      |
| - kernnel: ULONGLONG                   |
| - user: ULONGLONG                      |
| - idleSecond: ULONGLONG                |
| - kernnelSecond: ULONGLONG             |
| - userSecond: ULONGLONG                |
| - fliper: bool                         |
+----------------------------------------+
| + CPU()                                |
| + getIdelTime(): ULONGLONG             |
| + getKernelTime(): ULONGLONG           |
| + getUserTime(): ULONGLONG             |
| + getIdelTimeTwo(): ULONGLONG          |
| + getKernelTimeTwo(): ULONGLONG        |
| + getUserTimeTwo(): ULONGLONG          |
| + flipflip()                           |
| + getfliper(): bool                   |
| + CPUUsage(): float                   |
| + updateTimes()                        |
+----------------------------------------+
```
* Memory: This retrieves RAM load and checks for critical thresholds.
```text
+--------------------------------+
|             Memory             |
+--------------------------------+
| - memorystuf: DWORD            |
+--------------------------------+
| + Memory()                     |
| + getmemoryLod(): float        |
| + critLod(): bool              |
+--------------------------------+
```
* Disc: This queries filesystem statistics for available storage.
```text
+------------------------------+
|             disc             |
+------------------------------+
| - freeDGB: double            |
+------------------------------+
| + disc()                     |
| + getfreeDGB(): double       |
+------------------------------+
```
* Uptime: This manages system boot time and identifies the Operating System.
```text
+----------------------------------+
|             uptime               |
+----------------------------------+
| - months: ULONGLONG               |
| - seconds: ULONGLONG              |
| - minutes: ULONGLONG              |
| - hours: ULONGLONG                |
| - days: ULONGLONG                 |
+----------------------------------+
| + returnUPt(): std::string        |
| + getOSName(): std::string        |
+----------------------------------+
```

# Usage Examples
```text
========================================
       EMBEDDED SYSTEM MONITOR
       OS: Windows
========================================
CPU Utilization:    23.86%
Memory Load:        45.00%

Free Disk Space:    1776.94 GB
System Uptime:      4 months.11 days.7 hours.0 minutes.52 seconds.
========================================
```

# Important notes
- Permissions: On some Linux distributions, high-level system info might require standard user permissions to read /proc.
- Terminal Support: The dashboard uses \033[H and \033[2J for refreshing. Ensure your terminal supports ANSI escape sequences (standard in most modern shells).
