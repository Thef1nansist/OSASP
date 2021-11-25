#include <Windows.h>
#include <iostream>
#include <ctime>
#define SECOND 10000000

HANDLE htimer1 = NULL;
long long it1 = -3 * SECOND;
HANDLE htimer2 = NULL;
long long it2 = -15 * SECOND;

int i = 0;

DWORD WINAPI ChildThread() {
	while (true) {
		WaitForSingleObject(htimer1, INFINITE);
		std::cout << clock() << ": timer1" << "\n";
		std::cout << "iterations count: " << i << "\n\n";
	}

}

int main() {
	htimer1 = CreateWaitableTimer(NULL, FALSE, NULL);
	std::cout << clock() << ": start" << "\n\n";
	if (!SetWaitableTimer(htimer1, (LARGE_INTEGER*)&it1, 3000, NULL, NULL, FALSE)) throw "Error SetwaitableTimer";

	DWORD ChildId = 0;
	HANDLE hchild = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ChildThread, NULL, NULL, &ChildId);

	htimer2 = CreateWaitableTimer(NULL, FALSE, NULL);
	if (!SetWaitableTimer(htimer2, (LARGE_INTEGER*)&it2, 0, NULL, NULL, FALSE)) throw "Error SetwaitableTimer";

	while (true) {
		if (WaitForSingleObject(htimer2, 0) == WAIT_OBJECT_0) {
			std::cout << clock() << ": timer2" << "\n";
			std::cout << "breaking loop" << "\n\n";
			TerminateThread(hchild, 0);
			break;
		}
		i++;
		Sleep(10);
	}

	std::cout << "iterations count: " << i << "\n\n";

	system("pause");
	return 0;
}