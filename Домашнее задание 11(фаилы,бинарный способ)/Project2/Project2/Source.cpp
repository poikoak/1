#include<iostream>
using namespace std;
void main()
{
	/*2. Пользователь вводит имя файла.Программа разбивает его на 2 равные части и сохраняет в 2
		результирующих файла.*/

	char Filename[200];
	cout << "Enter name of source file: ";
	cin.getline(Filename, 200);

	char Filename2[200];
	cout << "Enter name of destination file: ";
	cin.getline(Filename2, 200);
	char Filename3[200];
	cout << "Enter name of destination file: ";
	cin.getline(Filename3, 200);


	FILE* File = fopen(Filename, "rb");
	if (File != nullptr)
	{
		fseek(File, 0, SEEK_END);
		size_t fileSize = ftell(File);
		fseek(File, 0, SEEK_SET);
		char* buffer = new char[fileSize];

		size_t q = fileSize / 2;

		if (buffer != nullptr)
		{
			fread(buffer, sizeof(char), fileSize, File);
			fseek(File, 0, SEEK_SET);

			char* buffer1 = new char[q];
			fread(buffer1, sizeof(char), q, File);

			FILE* dstFile1 = fopen(Filename2, "wb");
			if (dstFile1 != nullptr)
			{
				fwrite(buffer1, sizeof(char), q, dstFile1);
				fclose(dstFile1);
			}

			delete[] buffer1;


			size_t lengthFile2 = fileSize - q;
			char* buffer2 = new char[lengthFile2];

			fread(buffer2, sizeof(char), lengthFile2, File);
			FILE* dstFile2 = fopen(Filename3, "wb");
			if (dstFile2 != nullptr)
			{
				fwrite(buffer2, sizeof(char), lengthFile2, dstFile2);
				fclose(dstFile2);
			}

			delete[] buffer2;
		}

		delete[] buffer;


		fclose(File);
	}
}


	
	


