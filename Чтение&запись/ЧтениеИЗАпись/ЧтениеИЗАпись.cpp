#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	char path[] = "mather.txt";

	HANDLE hFile;

	hFile = CreateFileA((LPCTSTR)path, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ| FILE_SHARE_WRITE,
		NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		cout << "Ошибка выполнения программы №" << GetLastError() << endl;
		cin.get();
		return GetLastError();
	}

	cout << "Выберите действи:\n"
		<< "Запись в файл (1)\n"
		<< "Чтение файла (2)\n"
		<< "Введите номер действия:";

	int actionNum = 0;
	cin >> actionNum;

	if (actionNum == 1)
	{
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
	else if (actionNum == 2)
	{
		char buffer[256]; // надо вписать максимальное значение хронящееся в файле хз какое

		DWORD dwBytesToRead = sizeof(buffer) - 1;
		DWORD dwBytesRead = 0;

		bool readFile = ReadFile(hFile, (void*)buffer, dwBytesToRead, &dwBytesRead, NULL);

		if (dwBytesToRead > 0)
		{
			buffer[dwBytesRead] = '\0';
			cout << "Файл cодержит в себе:\n "
				<< buffer << endl;
		}
		CloseHandle(hFile);
		cin.get();
	}
	else
	{
		cout << "Ошибка выбора действия!" << endl;
		return 0;
	}
}
