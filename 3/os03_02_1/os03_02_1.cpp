#include <iostream>
#include <Windows.h>

int main()
{
	for (size_t i = 0; i < 50; i++)
	{
		std::cout <<"os03_02_1: idP:" << GetCurrentProcessId() << "\n";
		Sleep(1000);
	}
}
