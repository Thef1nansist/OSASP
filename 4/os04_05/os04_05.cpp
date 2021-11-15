#include <Windows.h>
#include <iostream>

DWORD pid = NULL;


DWORD WINAPI ChildThread() {
	DWORD tid = GetCurrentThreadId();
	for (int i = 0; i < 5; i++)
	{
		std::cout << " PID: " << pid << "os04_02_T1:  tid- " << tid << ": " << i << std::endl;
		Sleep(1000);
	}

	return 0;
}

DWORD WINAPI ChildSecondThread() {
	DWORD tid = GetCurrentThreadId();
	for (int i = 0; i < 12; i++)
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

	for (int i = 0; i < 10; i++)
	{
		
		std::cout << " PID: " << pid << " Parent Thread:  tid- " << tid << ": " << i << std::endl;
		Sleep(1000);
		if (i == 4) {
			std::cout << "\n Terminate os04_02_T2 \n";
			TerminateThread(hChildSecond, -1);
		}
	}

	WaitForSingleObject(hChild, INFINITE);
	CloseHandle(hChild);

}

