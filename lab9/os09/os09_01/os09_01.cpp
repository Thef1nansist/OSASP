#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>


time_t  filetimeToTimet(FILETIME const& ft) { ULARGE_INTEGER ull;    ull.LowPart = ft.dwLowDateTime;    ull.HighPart = ft.dwHighDateTime;    return ull.QuadPart / 10000000ULL - 11644473600ULL; }

BOOL printFileInfo(LPWSTR fileName) {
	std::cout << "*PRINT FILE INFO*\n";
	try {
		HANDLE hf = CreateFile(
			fileName,
			GENERIC_WRITE | GENERIC_READ,
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

		BY_HANDLE_FILE_INFORMATION fileInfo;

		GetFileInformationByHandle(hf, &fileInfo);
		DWORD fileType = GetFileType(hf);


		char filepath[20];
		wcstombs(filepath, fileName, 20);
		std::cout << "Filename: " << filepath << std::endl;
		if (fileType == FILE_TYPE_DISK) {
			std::cout << "Type: disk file" << std::endl;
		}
		else {
			std::cout << "Type: not disk file" << std::endl;
		}
		std::cout << "Size: " << fileInfo.nFileSizeLow << std::endl;

		time_t t = filetimeToTimet(fileInfo.ftCreationTime);
		char str[70];
		struct tm ttm;
		localtime_s(&ttm, &t);
		strftime(str, 70, "%d.%m.%Y %H:%M:%S", &ttm);
		std::cout << "Creation time: " << str << std::endl;

		t = filetimeToTimet(fileInfo.ftLastWriteTime);
		localtime_s(&ttm, &t);
		strftime(str, 70, "%d.%m.%Y %H:%M:%S", &ttm);
		std::cout << "Last change time: " << str << std::endl;

		CloseHandle(hf);
		return true;
	}
	catch (const char* em) { std::cout << "-- Error: " << em << " \n"; return false; }
}

BOOL printFileTxt(LPWSTR fileName) {
	std::cout << "*PRINT FILE TEXT*\n";
try
{
	HANDLE hf = CreateFile(
		fileName,
		GENERIC_WRITE | GENERIC_READ,
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

	ZeroMemory(buf, sizeof(buf));
	BOOL b = ReadFile(
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

	printFileInfo(fileName);
	std::cout << std::endl;
	printFileTxt(fileName);

	system("pause");
	return 0;
}