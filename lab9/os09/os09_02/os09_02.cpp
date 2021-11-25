#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>

BOOL delRowFileTxt(LPWSTR fileName, DWORD row) {
	char filepath[20];
	wcstombs(filepath, fileName, 20);
	std::cout << "*DELETE ROW FROM FILE*\n";
	std::cout << "Filepath: " << filepath << "\n";
	std::cout << "Row to delete: " << row << "\n\n";

	try
	{
		HANDLE hf = CreateFile(
			fileName,
			GENERIC_READ,
			NULL,
			NULL,
			OPEN_ALWAYS,
			FILE_ATTRIBUTE_NORMAL,
			NULL);

		if (hf == INVALID_HANDLE_VALUE) {
			std::cout << "Open file unsuccessfully\n";
			CloseHandle(hf);
			return false;
		}
		else {
			std::cout << "Open file successfully\n";
		}

		DWORD n = NULL;
		char buf[1024];
		BOOL b;

		ZeroMemory(buf, sizeof(buf));
		b = ReadFile(
			hf,
			&buf,
			sizeof(buf),
			&n,
			NULL
		);

		if (!b) {
			std::cout << "Read file unsuccessfully\n";
			CloseHandle(hf);
			return false;
		}
		else {
			std::cout << "Read file successfully\n";
			std::cout << "Number of readed bytes: " << n << "\n";
			std::cout << buf << std::endl;
			CloseHandle(hf);
		}

		HANDLE hAppend = CreateFile(fileName, // open Two.txt
			GENERIC_WRITE,         // open for writing
			NULL,          // allow multiple readers
			NULL,                     // no security
			OPEN_ALWAYS,              // open or create
			FILE_ATTRIBUTE_NORMAL,    // normal file
			NULL);                    // no attr. template


		char editedBuf[1024];
		ZeroMemory(editedBuf, sizeof(editedBuf));


		int line = 1;
		int j = 0;
		for (int i = 0; i < n; i++) {
			if (line == row) {
				
			}
			else {
				editedBuf[j] = buf[i];
				j++;
			}

			if (buf[i] == '\n') {
				line++;
			}
		}


		b = WriteFile(hAppend, 
			editedBuf, 
			n, 
			&n, 
			NULL);

		if (!b) {
			std::cout << "Write file unsuccessfully\n";
			CloseHandle(hAppend);
			return false;
		}
		else {
			std::cout << "Write file successfully\n";
			std::cout << "Number of writed bytes: " << j << "\n"; // not at all
			std::cout << editedBuf << std::endl;
			CloseHandle(hAppend);
			return true;
		}


	}
	catch (const char* em) { std::cout << "-- Error: " << em << " \n"; return false; }
}

int main() {
	char text[] = "../../os09_01.txt";
	wchar_t wtext[20];
	mbstowcs(wtext, text, strlen(text) + 1);
	LPWSTR fileName = wtext;

	delRowFileTxt(fileName, 1);
	delRowFileTxt(fileName, 3);
	delRowFileTxt(fileName, 8);
	delRowFileTxt(fileName, 10);

	system("pause");
	return 0;
}