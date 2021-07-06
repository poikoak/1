#include<iostream>
using namespace std;
int main()
{
	/*3. Пользователь вводит 2 имени файла. Программа объединяет их в 1 результирующий файл.*/
		char firstFilename[200];
		cout << "Enter name of first file: ";
		cin.getline(firstFilename, 200);

		
		char secondFilename[200];
		cout << "Enter name of second file: ";
		cin.getline(secondFilename, 200);

		char endFilename[200];
		cout << "Enter name of end file: ";
		cin.getline(endFilename, 200);

		
		FILE* firstFile = fopen(firstFilename, "rb");
		FILE* secondFile = fopen(secondFilename, "rb");

		if (firstFile != nullptr && secondFile != nullptr)
		{
			
			fseek(firstFile, 0, SEEK_END);
			fseek(secondFile, 0, SEEK_END);			
			size_t fileSize1 = ftell(firstFile);
			size_t fileSize2 = ftell(secondFile);		
			fseek(firstFile, 0, SEEK_SET);
			fseek(secondFile, 0, SEEK_SET);			
			FILE* resultFile = fopen(endFilename, "wb");
			char* buffer = new char[fileSize1];

			if (buffer != nullptr)
			{
				
				fread(buffer, sizeof(char), fileSize1, firstFile);
				fwrite(buffer, sizeof(char), fileSize1, resultFile);
				delete[] buffer;			
				buffer = new char[fileSize2];
				fread(buffer, sizeof(char), fileSize2, secondFile);				
				fseek(resultFile, fileSize1, SEEK_SET);
				fwrite(buffer, sizeof(char), fileSize2, resultFile);

				delete[] buffer;
				fclose(resultFile);
			}
			fclose(firstFile);
			fclose(secondFile);
		}
	
}
		








