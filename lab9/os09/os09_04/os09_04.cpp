#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>

BOOL printWatchRowFileTxt(LPWSTR folderPath, DWORD mlsec) {
	char folderpath[20];
	wcstombs(folderpath, folderPath, 20);
	std::cout << "*WATCH FILE*\n";
	std::cout << "Folder path: " << folderpath << "\n";
	std::cout << "Number of milliseconds to watch: " << mlsec << "\n\n";
	try {
		HANDLE hNotif = FindFirstChangeNotification(folderPath, 
			FALSE, 
			FILE_NOTIFY_CHANGE_SIZE);

		if (hNotif == INVALID_HANDLE_VALUE) {
			std::cout << "Watching to file changing event is unsuccessfull\n";
			CloseHandle(hNotif);
			return false;
		}
		else {
			std::cout << "Watching to file changing event is successfull\n";
		}


		bool bWait = true;
		DWORD dwWaitStatus;
		clock_t t1;
		clock_t t2;
		t1 = clock();
		while (bWait)
		{
			dwWaitStatus = WaitForSingleObject(hNotif, 0);

			if (dwWaitStatus == WAIT_OBJECT_0) {
				std::cout << "Size of the file in the directory is changed\n";
				if (FindNextChangeNotification(hNotif) == FALSE) {
					std::cout << "Some error was occurred with watching to the next event\n";
					CloseHandle(hNotif);
					return false;
				}
			}
			
			t2 = clock();
			int clockDifference = t2 - t1;
			double timeDifference = (double)clockDifference / CLOCKS_PER_SEC;
			if (timeDifference > mlsec/1000) {
				std::cout << "Watching is ended\n";
				std::cout << "Time passed: " << timeDifference << " seconds\n";
				break;
			}
		}


	}
	catch (const char* em) { std::cout << "-- Error: " << em << " \n"; return false; }
}

int main() {
	char folder[] = "../../";
	wchar_t wFolder[20];
	mbstowcs(wFolder, folder, strlen(folder) + 1);
	LPWSTR folderPath = wFolder;

	printWatchRowFileTxt(folderPath, 20000);

	system("pause");
	return 0;
}