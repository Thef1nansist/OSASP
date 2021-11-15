#include <iostream>
#include <Windows.h>

using namespace std;


void sh(HANDLE handle) {
	PROCESS_HEAP_ENTRY phe;
	phe.lpData = NULL;
	while (HeapWalk(handle, &phe))
	{
		cout << "-- addres = " << hex << phe.lpData
			<< ", size = " << dec << phe.cbData
			<< ((phe.wFlags & PROCESS_HEAP_REGION) ? " R" : "")
			<< ((phe.wFlags & PROCESS_HEAP_UNCOMMITTED_RANGE) ? " U" : "")
			<< ((phe.wFlags & PROCESS_HEAP_ENTRY_BUSY) ? " B" : "")
			<< endl;
	}
	cout << "--------------------" << endl;
}

int main()
{
	HANDLE hp = GetProcessHeap();

	sh(hp);

	int size = 300000;

	int* m = new int[size];

	cout << "-- m = " << hex << m << ", size = " << dec << size << endl;

	sh(hp);

}

