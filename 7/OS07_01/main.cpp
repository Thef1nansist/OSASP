#include <iostream>
#include <Windows.h>

using namespace std;

extern "C" HANDLE CreateThreadInAsm(int* i);

int main() {

	int j = 0;

	HANDLE handles[2];

	for (int i = 0; i < 2; i++)
		handles[i] = CreateThreadInAsm(&j);

	for (int i = 0; i < 2; i++)
		WaitForSingleObject(handles[i], INFINITE);

	cout << j;

	return 0;


}