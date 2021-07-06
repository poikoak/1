/**
 Пользователь задаёт исходную папку, программа подсчитывает общий размер
всех файлов в этой папке и в подпапках, а также подсчитывает количество подпапок
 * */
#include <iostream>
#include <io.h>

using namespace std;

void scan_dir(const char* dir_path, const char* mask, int& fileSize, int& folders)
{
	char* new_path = new char[4000];
	char* mask_path = new char[4000];
	strcpy(mask_path, dir_path);
	strcat(mask_path, "\\");
	strcat(mask_path, mask);
	// переменная, хранящая информацию об одном файле
	_finddata_t c_file;
	// адрес списка найденных файлов
	long hFile;	
	// найти файлы по маске и вернуть адрес списка найденных файлов и информацию о первом файле
	hFile = _findfirst(mask_path, &c_file);	
	if (strcmp(c_file.name, ".") != 0 && strcmp(c_file.name, "..") != 0){		
		// если файл является папкой
		if (c_file.attrib & _A_SUBDIR){			
			cout << c_file.name << "   " << "<DIR>" << endl;			
			// сформировать путь к подпапке
			strcpy(new_path, dir_path);
			strcat(new_path, "\\");
			// добавить к полному пути имя текущей папки
			strcat(new_path, c_file.name);
			//cout << "Go to -> " << new_path << endl;
			// рекурсивный вызов функции
			scan_dir(new_path, mask, fileSize, folders);			
		}
	}	
	// цикл для получения информации об остальных найденных файлах
	while (_findnext(hFile, &c_file) == 0)	{
		if (strcmp(c_file.name, ".") != 0 && strcmp(c_file.name, "..") != 0)		{
			if (c_file.attrib & _A_SUBDIR)			{
				folders++;				
				// сформировать путь к подпапке
				cout << c_file.name << "   " << "<DIR>" << endl;				
				strcpy(new_path, dir_path);
				strcat(new_path, "\\");
				// добавить к полному пути имя текущей папки
				strcat(new_path, c_file.name);		
				// рекурсивный вызов функции
				scan_dir(new_path, mask, fileSize, folders);				
			}	
			fileSize = fileSize + c_file.size;
		}	
	}
	
	// освободить память от списка найденных файлов
	_findclose(hFile);
	delete[] new_path;
	delete[] mask_path;
}
void main(){
	int fileSize=0;
	int folders=0;
	scan_dir("g:\\1", "*.*",fileSize, folders);
	cout<<"total size = " << fileSize << endl;
	cout << "count folders = " << folders << endl;
}



