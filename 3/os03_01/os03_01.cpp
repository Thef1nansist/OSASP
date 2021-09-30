#include <iostream>
#include <Windows.h>

int main()
{
	for (size_t i = 0; i < 100; i++)
	{
		std::cout<<"idP:" << GetCurrentProcessId() << "\n";
		Sleep(10000);
	}
}

