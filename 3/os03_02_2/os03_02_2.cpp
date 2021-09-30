#include <iostream>
#include <Windows.h>

int main()
{
	for (size_t i = 0; i < 125; i++)
	{
		std::cout << "os03_02_2: idP:" << GetCurrentProcessId() << "\n";
		Sleep(1000);
	}
}