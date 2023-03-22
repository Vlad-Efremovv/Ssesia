#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	char path[] = "M:\\mather.txt";

	HANDLE hFile;

	hFile = CreateFileA((LPCTSTR)path, GENERIC_READ | GENERIC_WRITE, 0,
		NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		cout << "Ошибка выполнения программы №" << GetLastError() << endl;
		cin.get();
		return GetLastError();
	}
	
		cout << "Операция прошла успешно!" << endl;

		string str = "";
		cout << "Введите данные для файла:" << endl;
		cin.ignore();
		getline(cin, str);

		DWORD dwBittesWrite;

		WriteFile(hFile, str.c_str(), str.length(), &dwBittesWrite, NULL);
		if (WriteFile == FALSE)
		{
			cout << "Ошибка записи файла!";
			cin.get();
			return GetLastError();
		}

		CloseHandle(hFile);
		cin.get();

	
}