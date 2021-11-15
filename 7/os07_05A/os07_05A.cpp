#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	HANDLE he = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"smwEvent");

	if (he == NULL)
	{
		cout << "os07_04A: Open error Event\n";
	}
	else
	{
		cout << "OS07_04A: Open Event\n";
	}

	WaitForSingleObject(he, INFINITE);
	for (int i = 1; i <= 90; i++)
	{
		SetEvent(he);
		Sleep(100);
		cout << "os07_04A: " << i << " PID: " << GetCurrentProcessId() << endl;
	}
	CloseHandle(he);
	system("pause");

	return 0;
}
