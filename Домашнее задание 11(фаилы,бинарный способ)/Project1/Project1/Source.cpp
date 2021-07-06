#include<iostream>
using namespace std;
void main()
{
	/*1. Пользователь вводит имя файла.Программа удаляет из него все гласные буквы и сохраняет в
		другой файл(бинарный способ)*/
	
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
			char c = ' ';

			strcpy(buffer, " ");
			fread(buffer, sizeof(char), fileSize, srcFile);
			
			for (int i = 0; buffer[i] != 0; i++)
						{    
				if (buffer[i] == 'A' || buffer[i] == 'O' || buffer[i] == 'I' || buffer[i] == 'E' || buffer[i] == 'U' || buffer[i] == 'Y' ||
					buffer[i] == 'a' || buffer[i] == 'o' || buffer[i] == 'i' || buffer[i] == 'e' || buffer[i] == 'u' || buffer[i] == 'y')
					buffer[i] = c;
						}
		
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
}








//char firstfile[200];
	//cout << "Enter name of first file: ";
	//cin.getline(firstfile, 200);
	////куда копируем
	//char filecopy[200];
	//cout << "enter a destination file: ";
	//cin.getline(filecopy, 200);
	////открыв для чтения
	//FILE* sFile = fopen(firstfile, "rb");
	//if (sFile != nullptr)
	//{

	//	size_t fileSize = ftell(sFile);
	//	fseek(sFile, 0, SEEK_SET);
	//	char* buffer1 = new char[fileSize];
	//	if (buffer1 != nullptr)
	//	{

	//		fread(buffer1, sizeof(char), fileSize, sFile);
	//		//for (int i = 0; buffer1[i] != 0; i++)
	//		//{    // идем по символам
	//		//	if (buffer1[i] == 'A' || buffer1[i] == 'O' || buffer1[i] == 'I' || buffer1[i] == 'E' || buffer1[i] == 'U' || buffer1[i] == 'Y' ||
	//		//		buffer1[i] == 'a' || buffer1[i] == 'o' || buffer1[i] == 'i' || buffer1[i] == 'e' || buffer1[i] == 'u' || buffer1[i] == 'y')
	//		//		buffer1[i] = buffer1[i + 1];
	//		//}

	//		FILE* dFile = fopen(filecopy, "wb");
	//		if (dFile != nullptr)
	//		{
	//			fwrite(buffer1, sizeof(char), fileSize, dFile);
	//			fclose(dFile);
	//		}
	//		delete[] buffer1;
	//	}
	//	
	//	fclose(sFile);
	/*}*/
