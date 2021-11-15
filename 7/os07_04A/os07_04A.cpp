#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{

	HANDLE hs = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, L"smwSem");
	if (hs == NULL)
	{
		cout << "os07_04A: Open error Semaphore\n";
	}
	else
	{
		cout << "OS07_04A: Open Semaphore\n";
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
			cout << "os07_04A: prevcount = " << prevcount << endl;
		}
		Sleep(100);
		cout << "os07_03A: " << i << " PID: " << GetCurrentProcessId() << endl;
	}

	CloseHandle(hs);
	system("pause");

	return 0;
}
