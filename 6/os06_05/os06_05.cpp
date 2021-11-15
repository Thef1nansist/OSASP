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
	HANDLE hp = HeapCreate(HEAP_NO_SERIALIZE | HEAP_ZERO_MEMORY, 4096, 4096);

	sh(hp);

	int* m = (int*)HeapAlloc(hp, HEAP_NO_SERIALIZE | HEAP_ZERO_MEMORY, 500 * sizeof(int));

	cout << "-- address = " << hex << m << endl;
	sh(hp);

	HeapFree(hp, HEAP_NO_SERIALIZE, m);
	sh(hp);

	HeapDestroy(hp);

	system("pause");

}


