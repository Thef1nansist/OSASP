#include <iostream>
#include <Windows.h>
#include <ctime>

using namespace std;

int main()
{
	int count = 0;

	clock_t start_time = clock();
	while (double((clock() - start_time) / CLOCKS_PER_SEC) < 15)
	{
		count++;
		
		if (double((clock() - start_time) / CLOCKS_PER_SEC) == 5)
		{
			cout << "After 5 second: " << count << endl;
			Sleep(1000);
		}

		if (double( - start_time) / CLOCKS_PER_SEC) == 10)
		{
			cout << "After 10 second: " << count << endl;
			Sleep(1000);
		}

	}

	cout << "End count: " << count;
}

