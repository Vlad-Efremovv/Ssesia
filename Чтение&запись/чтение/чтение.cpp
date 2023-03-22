#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	char path[] = "M:\\mather.txt";

	HANDLE hFile;

	hFile = CreateFileA((LPCTSTR)path, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ,
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		cout << "Ошибка выполнения программы №" << GetLastError() << endl;
		cin.get();
		return GetLastError();
	}

	char buffer[256]; // надо вписать максимальное значение хронящееся в файле хз какое

	DWORD dwBytesToRead = sizeof(buffer) - 1;
	DWORD dwBytesRead = 0;

	bool readFile = ReadFile(hFile, (void*)buffer, dwBytesToRead, &dwBytesRead, NULL);

	if (dwBytesToRead>0)
	{
		buffer[dwBytesRead] = '\0';
		cout << "Файл cодержит в себе:\n "
			<< buffer << endl;
	}
	CloseHandle(hFile);
	cin.get();
}
