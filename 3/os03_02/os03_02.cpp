#include <iostream>
#include <Windows.h>

int main()
{
	LPCWSTR an = L"D:\\5sem\\OSASP\\Labs\\3\\os03_02\\Debug\\os03_02_1.exe";
	LPCWSTR an2 = L"D:\\5sem\\OSASP\\Labs\\3\\os03_02\\Debug\\os03_02_2.exe";
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);

	if (CreateProcess(an,
		NULL,
		NULL,
		NULL,
		FALSE,
		CREATE_NEW_CONSOLE,
		NULL,
		NULL,
		&si,
		&pi))
	{
		std::cout << "-- Process OS03_02_1 created\n";
	}
	else 
	{
		std::cout << "-- Process OS03_02_1 not created\n";
	}

	if (CreateProcess(an2,
		NULL,
		NULL,
		NULL,
		FALSE,
		CREATE_NEW_CONSOLE,
		NULL,
		NULL,
		&si,
		&pi))
	{
		std::cout << "-- Process OS03_02_2 created\n";
	}
	else
	{
		std::cout << "-- Process OS03_02_2 not created\n";
	}

	for (size_t i = 0; i < 100; i++)
	{
		std::cout<<i<< ".idP:" << GetCurrentProcessId() << "\n";
		Sleep(1000);
	}

	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hProcess);
}