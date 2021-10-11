#include <Windows.h>
#include <iostream>
#include <cassert>
#include <sstream>

void CreateProccersWithPriority(LPCWSTR an, STARTUPINFO si, int priority)
{
    PROCESS_INFORMATION pi;
    if (priority == 1)
    {
        if (CreateProcess(an, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE | IDLE_PRIORITY_CLASS, NULL, NULL, &si, &pi))
            std::cout << "-- Process OS05_021 created\n";
        else  std::cout << "-- Process OS05_021 not created\n";
    }
    if (priority == 2)
    {
        if (CreateProcess(an, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE | NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi))
            std::cout << "-- Process OS05_021 created\n";
        else  std::cout << "-- Process OS05_021 not created\n";
    }
    if (priority == 3)
    {
        if (CreateProcess(an, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE | HIGH_PRIORITY_CLASS, NULL, NULL, &si, &pi))
            std::cout << "-- Process OS05_021 created\n";
        else  std::cout << "-- Process OS05_021 not created\n";
    }
    if (priority == 4)
    {
        if (CreateProcess(an, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE | REALTIME_PRIORITY_CLASS, NULL, NULL, &si, &pi))
            std::cout << "-- Process OS05_021 created\n";
        else  std::cout << "-- Process OS05_021 not created\n";
    }
}


int main(int argc, char* argv[])
{
    for (int i = 0; i < argc; i++)
    {
        std::cout << "arg" << i << ": " << argv[i] << "\n";
    }

    HANDLE hp = GetCurrentProcess();
    try
    {
        {
            DWORD pa = NULL, sa = NULL, icpu = -1;
            if (!GetProcessAffinityMask(hp, &pa, &sa)) throw "GetProcessAffinityMask";
            std::cout << " Process Affinity Mask: " << std::showbase << std::hex << pa << "\n";
            std::cout << " System Affinity Mask: " << std::showbase << std::hex << sa << "\n";
            std::cout << std::dec << std::noshowbase << "\n\n";


            if (argv[1] != NULL)
            {
                unsigned long long mask;
                /*assert(sizeof argv[1] == sizeof(mask));*/
                sscanf_s(argv[1], "%d", &mask);
                if (!SetProcessAffinityMask(hp, mask)) throw "SetProcessAffinityMask";

                if (!GetProcessAffinityMask(hp, &pa, &sa)) throw "GetProcessAffinityMask";
                std::cout << " Process Affinity Mask: " << std::showbase << std::hex << pa << "\n";
                std::cout << " System Affinity Mask: " << std::showbase << std::hex << sa << "\n";
                std::cout << std::dec << std::noshowbase;

                if (argv[2] != NULL)
                {
                    STARTUPINFO si;
                    ZeroMemory(&si, sizeof(STARTUPINFO));
                    si.cb = sizeof(STARTUPINFO);

                    unsigned long long priority;
                    sscanf_s(argv[2], "%d", &priority);
                    CreateProccersWithPriority(L"D:\\учеба\\OSSP\\labs\\lab5\\OSSP_lr5\\Debug\\Process1.exe", si, priority);


                    if (argv[3] != NULL)
                    {
                        sscanf_s(argv[3], "%d", &priority);
                        ZeroMemory(&si, sizeof(STARTUPINFO));
                        si.cb = sizeof(STARTUPINFO);
                        CreateProccersWithPriority(L"D:\\учеба\\OSSP\\labs\\lab5\\OSSP_lr5\\Debug\\Process2.exe", si, priority);
                    }

                }
            }

        }
    }
    catch (char* msg) { std::cout << "Error " << msg << "\n"; }
}