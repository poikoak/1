#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <io.h>
#include <direct.h>
#include <cstdio> 
#include <fstream>

using namespace std;

//Разработать командный интерпретатор(по типу cmd), который понимает следующие команды :
//-cls - очистка экрана
//- exit - выход из программы
//- dir - показать содержимое текущей папки
//- type - показать содержимое файла(пример : type c : \temp\text.txt)

//-cd - смена текущего каталога
//примеры :
//
//cd \ - перейти в корневой каталог
//cd c : \temp\text - перейти в каталог c : \temp\text
//cd .. - перейти в родительский каталог
//
//copy - копирование файлов
//пример :
//copy c : \test\file.txt d : \ttt\test2.txt
//copy c : \test\ * .txt d : \ttt
//
//delete - удаление файлов
//delete c:\ * .*
//delete c:\test.txt
int cd(char*d_path, char* c_path)
{
	if (_chdir(d_path) == 0)
	{
		_getcwd(c_path, 4000);
	}
	return 0;
}
int dir()
{
	//массив char для хранения в нем полного пути к текущей папке
	char* dir = new char[4000];

	//команда _getcwd записывает в current_dir полный путь к папке, где находится исполняемый файл
	if (_getcwd(dir, 4000) != 0)
		cout << "Current directory is: " << dir << endl;
	else
		cout << "Error! Path not found!" << endl;
	strcat(dir, "\\");
	strcat(dir, "*.*");

	//перебор и вывод на экран содержимого папки
	_finddata_t c_file;
	long hFile;
	hFile = _findfirst(dir, &c_file);

	if (strcmp(c_file.name, ".") != 0 && strcmp(c_file.name, "..") != 0)
	{
		if (c_file.attrib & _A_SUBDIR)
			cout << c_file.name << "   " << "<DIR>" << endl;
		else
			cout << c_file.name << "   " << c_file.size << endl;
	}

	while (_findnext(hFile, &c_file) == 0)
	{
		if (strcmp(c_file.name, ".") != 0 && strcmp(c_file.name, "..") != 0)
		{
			if (c_file.attrib & _A_SUBDIR)
				cout << c_file.name << "   " << "<DIR>" << endl;
			else
				cout << c_file.name << "   " << c_file.size << endl;
		}
	}
	_findclose(hFile);
	delete[] dir;
	cout << "\n";
	return 0;
}


void type()
{
	cout << "Enter file path:" << endl;
	char* FILEp = new char[400];
	cin.getline(FILEp, 4000);	
	FILE* file = fopen(FILEp, "rb");
	if (file != nullptr)
	{
		fseek(file, 0, SEEK_END);
		size_t FileSize = ftell(file);
		fseek(file, 0, SEEK_SET);

		char* buffer = new char[FileSize];

		fread(buffer, sizeof(char), FileSize, file);
		fclose(file);

		//вывод данных из буфера
		for (size_t i = 0; i < FileSize; i++)
		{
			cout << buffer[i];
		}
		cout << "\n";

		delete[] buffer;
	}
	else
		cout << "Error opening file!" << endl;

	delete[] FILEp;
	
}

int deleted()
{

	cout << "Enter file path:" << endl;
	char* FILEp = new char[4000];
	cin.getline(FILEp, 4000);
	FILE* file = fopen(FILEp, "rb");
	if (file != nullptr)
	{
		fseek(file, 0, SEEK_END);
		size_t FileSize = ftell(file);
		fseek(file, 0, SEEK_SET);

		char* buffer = new char[FileSize];

		fread(buffer, sizeof(char), FileSize, file);
		fclose(file);
		if ( remove(FILEp) != 0)             // удаление файла 
			cout << "Error""\n";
		else
			cout << "Fail deleted""\n";
		return 0;
		delete[] buffer;

	}

	delete[] FILEp;

}


int copy()
{

	char sourceFilename[200];
	cout << "Enter name of source file: ";
	cin.getline(sourceFilename, 200);

	char destFilename[200];
	cout << "Enter name of destination file: ";
	cin.getline(destFilename, 200);


	FILE* srcFile = fopen(sourceFilename, "rb");
	if (srcFile != nullptr)
	{
		fseek(srcFile, 0, SEEK_END);
		size_t fileSize = ftell(srcFile);
		fseek(srcFile, 0, SEEK_SET);
		char* buffer = new char[fileSize];

		if (buffer != nullptr)
		{

			strcpy(buffer, " ");
			fread(buffer, sizeof(char), fileSize, srcFile);

			FILE* dstFile = fopen(destFilename, "wb");
			if (dstFile != nullptr)
			{
				fwrite(buffer, sizeof(char), fileSize, dstFile);
				fclose(dstFile);
			}

			delete[] buffer;
		}
		fclose(srcFile);
	}
	return 0;
}

void main()
{

	cout << "1. - cls" << endl;
	cout << "2. - type" << endl;
	cout << "3. - dir" << endl;
	cout << "4. - exit" << endl;
	cout << "5. - delete" << endl;
	cout << "6. - copy" << endl;
	cout << "7. - cd" << endl;

	while (true)
	{
		char* str = new char[80];
		cout << "Enter operation: ";
		cin.getline(str, 80);

		if (strcmp(str, "dir") == 0)
			dir();


		else if (strcmp(str, "exit") == 0)
		{
			cout << "Goodbye ";
			exit(0);
		}

		else if (strcmp(str, "type") == 0)
			type();

		else if (strcmp(str, "cls") == 0)
		{
			system("cls");
		}
		else if (strcmp(str, "delete") == 0)
		{
			deleted();
		}
		else if (strcmp(str, "copy") == 0)
		{
			copy();
		}
		else if (strcmp(str, "cd") == 0)
		{

			char cur_path[4000];
			_getcwd(cur_path, 4000);
			cout << endl;
			cout << cur_path << ">";
			char sourceFilename[200];
			cin.getline(sourceFilename, 200);
			cd(sourceFilename, cur_path);
		}
			else cout << "Invalid command!" << endl;
		

	}

}