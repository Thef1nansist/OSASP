#include <Windows.h>
#include <iostream>

using namespace std;


int main()
{
    PROCESS_INFORMATION pi1, pi2;
    DWORD pId = GetCurrentProcessId();
    LPCWSTR an1 = L"D:\\5sem\\OSASP\\Labs\\7\\os07_02\\Debug\\os07_04A.exe";
    LPCWSTR an2 = L"D:\\5sem\\OSASP\\Labs\\7\\os07_02\\Debug\\os07_04B.exe";
    HANDLE hs = CreateSemaphore(NULL, 2, 2, L"smwSem");
    {
        STARTUPINFO si;
        ZeroMemory(&si, sizeof(STARTUPINFO));
        si.cb = sizeof(STARTUPINFO);

        if (CreateProcess(an1, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi1))
        {
            cout << "--Process os07_04A created\n";
        }
        else
        {
            cout << "--Process os07_04A not created\n";
        }
    }
    {
        STARTUPINFO si;
        ZeroMemory(&si, sizeof(STARTUPINFO));
        si.cb = sizeof(STARTUPINFO);

        if (CreateProcess(an2, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi2))
        {
            cout << "--Process os07_03B created\n";
        }
        else
        {
            cout << "--Process os07_03B not created\n";
        }

        LONG prevcount = 0;
        for (int i = 1; i <= 90; i++)
        {
            if (i == 30)
            {
                WaitForSingleObject(hs, INFINITE);
            }
            if (i == 60)
            {
                ReleaseSemaphore(hs, 1, &prevcount);
                cout << "os07_04: prevcount = " << prevcount << endl;
            }
            cout << "PID = " << pId << ", Main Thread: " << i << endl;
            Sleep(100);
        }

        WaitForSingleObject(pi1.hProcess, INFINITE);
        WaitForSingleObject(pi2.hProcess, INFINITE);
        CloseHandle(hs);
        CloseHandle(pi1.hProcess);
        CloseHandle(pi2.hProcess);

        return 0;
    }

}


