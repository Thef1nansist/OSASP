#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	HANDLE hm = OpenMutex(SYNCHRONIZE, FALSE, L"smwMutex");
	if (hm == NULL)
	{
		cout << "os07_03A: Open err Mutex\n";
	}
	else
	{
		cout << "OS07_03A: Open  Mutex\n";
	}

	for (int i = 0; i < 90; i++)
	{
		if (i == 30)
		{
			WaitForSingleObject(hm, INFINITE);
		}
		if (i == 60)
		{
			ReleaseMutex(hm);
		}
		Sleep(100);
		cout << "os07_03A: " << i << " PID: " << GetCurrentProcessId() << endl;
		if (i == 60)
		{
			WaitForSingleObject(hm, INFINITE);
			ReleaseMutex(hm);
		}
	}
}
