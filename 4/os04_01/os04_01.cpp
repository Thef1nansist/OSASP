#include <Windows.h>
#include <iostream>

int main()
{
    DWORD pid = GetCurrentProcessId();
    DWORD tid = GetCurrentThreadId();
    
    for (int i = 0; i < 100; i++)
    {
        std::cout << "Pid: " << pid << " Tid: " << tid << std::endl;
        Sleep(1000);
    }
}
