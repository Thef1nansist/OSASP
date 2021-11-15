#include <Windows.h>
#include <iostream>
#include "os04_02.h"

DWORD pid = NULL;


DWORD WINAPI ChildThread() {
	DWORD tid = GetCurrentThreadId();
	for (int i = 0; i < 50; i++)
	{
			std::cout << " PID: " << pid << "os04_02_T1:  tid- " << tid << ": " << i << std::endl;
			Sleep(1000);
	}

	return 0;
}

DWORD WINAPI ChildSecondThread() {
	DWORD tid = GetCurrentThreadId();
	for (int i = 0; i < 125; i++)
	{
		std::cout << " PID: " << pid << "; os04_02_T2:  tid- " << tid << ": " << i << std::endl;
		Sleep(1000);
	}

	return 0;
}



int main()
{
	pid = GetCurrentProcessId();

	DWORD tid = GetCurrentThreadId();
	DWORD childId = NULL;
	DWORD childSecondId = NULL;
	HANDLE hChild = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ChildThread, NULL, 0, &childId);
	HANDLE hChildSecond = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ChildSecondThread, NULL, 0, &childSecondId);

	for (int i = 0; i < 100; i++)
	{
		std::cout << " PID: " << pid << " Parent Thread:  tid- " << tid << ": " << i << std::endl;
		Sleep(1000);
	}

	WaitForSingleObject(hChild, INFINITE);
	CloseHandle(hChild);

}

