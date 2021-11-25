#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>

BOOL insRowFileTxt(LPWSTR fileName, LPWSTR str, DWORD row) { // row = 1 -> in the beginning; row = -1 -> in the end;
	char filepath[20];
	wcstombs(filepath, fileName, 20);
	char stringToInsert[50];
	wcstombs(stringToInsert, str, 50);
	std::cout << "*INSERT ROW TO FILE*\n";
	std::cout << "Filepath: " << filepath << "\n";
	std::cout << "String to insert: " << stringToInsert << "\n";
	std::cout << "Row to insert: " << row << "\n\n";

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
		int k = 0;
		for (int i = 0; i < n; i++) {
			if (line == row) {
				for (int k = 0; k < sizeof(stringToInsert); k++) {
					editedBuf[j] = str[k];
					j++;
					if (str[k + 1] == '\0') {
						editedBuf[j] = '\r';
						j++;
						editedBuf[j] = '\n';
						j++;
						row = 0; 
						break;
					}
				}
				i--;
			}
			else {
				editedBuf[j] = buf[i];
				j++;
			}

			if (buf[i] == '\n') {
				line++;
			}

			if (buf[i + 1] == '\0' && row == -1) {
				for (int k = 0; k < sizeof(stringToInsert); k++) {
					editedBuf[j] = str[k];
					j++;
					if (str[k + 1] == '\0') {
						editedBuf[j] = '\r';
						j++;
						editedBuf[j] = '\n';
						j++;
						row = 0;
						break;
					}
				}
			}
		}


		b = WriteFile(hAppend,
			editedBuf,
			j,
			&n,
			NULL);

		if (!b) {
			std::cout << "Write file unsuccessfully\n";
			CloseHandle(hAppend);
			return false;
		}
		else {
			std::cout << "Write file successfully\n";
			std::cout << "Number of writed bytes: " << n << "\n";
			std::cout << editedBuf << std::endl;
			CloseHandle(hAppend);
			return true;
		}


	}
	catch (const char* em) { std::cout << "-- Error: " << em << " \n"; return false; }
}

int main() {
	char filePath[] = "../../os09_01.txt";
	wchar_t wFilePath[20];
	mbstowcs(wFilePath, filePath, strlen(filePath) + 1);
	LPWSTR fileName = wFilePath;

	char str[] = "INSERTED ROW";
	wchar_t wStr[50];
	mbstowcs(wStr, str, strlen(str) + 1);
	LPWSTR strToIns = wStr;

	insRowFileTxt(fileName, strToIns, 1);
	insRowFileTxt(fileName, strToIns, -1);
	insRowFileTxt(fileName, strToIns, 5);
	insRowFileTxt(fileName, strToIns, 7);

	system("pause");
	return 0;
}