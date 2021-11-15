#include <Windows.h>
#include <iostream>

DWORD pid = NULL;
int flag = false;


DWORD WINAPI ChildThread() {
	DWORD tid = GetCurrentThreadId();
	for (int i = 0; i < 5; i++)
	{
		std::cout << " PID: " << pid << "os04_02_T1:  tid- " << tid << ": " << i << std::endl;
		Sleep(1000);
		if (i == 25) {
			std::cout << "Suspend os04_02_T2 \n";
			Sleep(10000);
			std::cout << "Wakeup os04_02_T1 \n";
		}
	}

	return 0;
}

DWORD WINAPI ChildSecondThread() {
	DWORD tid = GetCurrentThreadId();
	for (int i = 0; i < 12; i++)
	{
		std::cout << " PID: " << pid << "; os04_02_T2:  tid- " << tid << ": " << i << std::endl;
		Sleep(1000);
		if (i == 80) {
			std::cout << "Suspend os04_02_T2 \n";
			Sleep(15000);
			std::cout << "Wakeup os04_02_T2 \n";
		}
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
		if (i == 30) {
			std::cout << "Suspend os04_02 \n";
			Sleep(10000);
		}
	}



	WaitForSingleObject(hChild, INFINITE);
	CloseHandle(hChild);

}
