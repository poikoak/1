#include <iostream>
using namespace std;

void main()
{
	//_CRT_SECURE_NO_WARNINGS
	//2. Пользователь вводит 2 имени файла, программа копирует все строки из первого файла во второй.

	char s[80];
	cout << "enter first file name: " << endl;
	cin.getline(s, 80);
	FILE* file1 = fopen(strcat(s, ".txt"), "w");
	if (file1 != nullptr )
	{
		fputs("hello world", file1);
		fputs("\n123", file1);
		fputs("\nqwt", file1);
		fclose(file1);	
	}
	else
	{
		cout << "Error opening file!" << endl;
	}

	file1 = fopen(s, "r");


	char s2[80];
	cout << "enter second file name: " << endl;
	cin.getline(s2, 80);
	FILE* file2 = fopen(strcat(s2, ".txt"), "w");
	
	if (file1 != nullptr && file2 != nullptr)
	{
		char buffer1[80];		
		while (!feof(file1))
		{							
			strcpy(buffer1, "");
			fgets(buffer1, 80, file1);			
			fputs(buffer1, file2);			
		}
		fclose(file1);
		fclose(file2);
	}
	else
	{
		cout << "Error opening file!" << endl;
	}	
}
