#include <iostream>
#include <io.h>
using namespace std;
//1. Пользователь вводит путь к исходной папке, программа копирует все файлы из исходной
//папки в результирующую папку, которую тоже указывает пользователь.
void copyFile(const char* src, const char* dest) 
{
	FILE* srcFile = fopen(src, "rb");
	if (srcFile != nullptr)
	{
		fseek(srcFile, 0, SEEK_END);
		size_t fileSize = ftell(srcFile);
		fseek(srcFile, 0, SEEK_SET);
		char* buffer = new char[fileSize+1];
        fread(buffer, sizeof(char), fileSize, srcFile);
        fclose(srcFile);
        FILE* dstFile = fopen(dest, "wb");
		 if (dstFile != nullptr)
			{
				fwrite(buffer, sizeof(char), fileSize, dstFile);
				fclose(dstFile);
			}
			delete[] buffer;
	}
		
}
  
void copyFiles(const char* src, const char* dest)
{
const unsigned qwe = 300;
char* Src = new char[qwe];
char* Dest = new char[qwe];
char* mask = new char[qwe];
strcpy(mask, src);
strcat(mask, "\\");
strcat(mask, "*.*");
_finddata_t cFile;
long hFile;
hFile = _findfirst(mask, &cFile);
if (strcmp(cFile.name, ".") != 0 && strcmp(cFile.name, "..") != 0)
{
    if (!(cFile.attrib & _A_SUBDIR)) 
    {
        strcpy(Src, src);
        strcat(Src, "\\");
        strcat(Src, cFile.name);
        strcpy(Dest, dest);
        strcat(Dest, "\\");
        strcat(Dest, cFile.name);
        copyFile(Src, Dest);
        strcpy(Src, "");
        strcpy(Dest, "");
    }
}

while (_findnext(hFile, &cFile) == 0)
{
    if (strcmp(cFile.name, ".") != 0 && strcmp(cFile.name, "..") != 0)
    {
        if (!(cFile.attrib & _A_SUBDIR)) 
        {

            strcpy(Src, src);
            strcat(Src, "\\");
            strcat(Src, cFile.name);
            strcpy(Dest, dest);
            strcat(Dest, "\\");
            strcat(Dest, cFile.name);
            copyFile(Src, Dest);
            strcpy(Src, "");
            strcpy(Dest, "");
        }
    }
}

_findclose(hFile);

delete[]Src;
delete[]Dest;
delete[]mask;
}




int main() {
	const unsigned file = 300;
	char* src = new char[file];
	char* dest = new char[file];
	cout << "Type a path to the source dir!" <<endl;
	cin.getline(src, file);
	cout << "Type a path where to copy!" <<endl;
	cin.getline(dest, file);
	copyFiles(src, dest);
	delete[] src;
	delete[] dest;	
}


