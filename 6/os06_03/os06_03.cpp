#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <locale>

using namespace std;
#define PG (4096)
int pg = 256;

int main()
{
	setlocale(LC_ALL, "rus");
	SYSTEM_INFO system_info;
	GetSystemInfo(&system_info);

	int* virtArrar = (int*)VirtualAlloc(NULL, pg * PG, MEM_COMMIT, PAGE_READWRITE);
	for (int i = 0; i < pg * PG/4; i++)
	{
		virtArrar[i] = i;
	}

	int index = ('S' * system_info.dwPageSize + (L'V' << 4) + (L'Y' << 4)) / sizeof(int);

	cout << virtArrar[index] << endl;

	cout << endl;
}