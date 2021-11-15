#include <iostream>
#include <Windows.h>

int main()
{
	for (int i = 0; i < 10000000; i++)
	{
		std::cout << "Pid: " << GetCurrentProcessId() << std::endl;
		Sleep(1000);
	}
}