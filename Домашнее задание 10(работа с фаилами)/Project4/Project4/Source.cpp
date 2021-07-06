#include <iostream>
using namespace std;
//_CRT_SECURE_NO_WARNINGS

//4. Пользователь вводит 2 имени файла, программа копирует
//только те строки из первого файла во второй, которые являются числами.

void main()
{
	char s[80];
	cout << "enter first file name: " << endl;
	cin.getline(s, 80);
	FILE* file1 = fopen(strcat(s, ".txt"), "w");
	if (file1 != nullptr)
	{
		fputs("hello world", file1);
		fputs("\n123", file1);
		fputs("\nqwt", file1);
		fputs("\nqw1ysa", file1);
		fclose(file1);
	}
	else
	{
		cout << "Error opening file!" << endl;
	}

	


	char s2[80];
	cout << "enter second file name: " << endl;
	cin.getline(s2, 80);
	FILE* file2 = fopen(strcat(s2, ".txt"), "w");
	
	if (file2 != nullptr)
	{
		int str;
		int count = 0;
		char buffer1[200];
		file1 = fopen(s, "r");
		while (!feof(file1))
		{
			strcpy(buffer1, "");

			fgets(buffer1, 200, file1);
			count = 0;
			str = strlen(buffer1);
			for (int i = 0; buffer1[i] !=0; i++)
			{    // идем по символам
				if (buffer1[i] >= '0' && buffer1[i] <= '9') count++;
			}
			if (str - 1 == count)
			{
				fputs(buffer1, file2);
				
			}
			

		}
		fclose(file1);
		fclose(file2);

	}

	else
	{
		cout << "Error opening file!" << endl;
	}

}


