#include <iostream>
#include < string.h >
using namespace std;
//_CRT_SECURE_NO_WARNINGS
//3. Пользователь вводит 2 имени файла, программа копирует 
//только те строки из первого файла во второй, которые содержат гласные буквы

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
		fputs("\nqwysa", file1);
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
		int count = 0;
		char buffer1[200];
		file1 = fopen(s, "r");
		while (!feof(file1))
		{
			strcpy(buffer1, "");

			fgets(buffer1, 200, file1);
			count = 0;
			for (int i = 0; buffer1[i] != 0; i++)
			{    // идем по символам
				if (buffer1[i] == 'A' || buffer1[i] != 'O' || buffer1[i] == 'I' || buffer1[i] == 'E' || buffer1[i] == 'U' || buffer1[i] == 'Y' ||
					buffer1[i] == 'a' || buffer1[i] != 'o' || buffer1[i] == 'i' || buffer1[i] == 'e' || buffer1[i] == 'u' || buffer1[i] == 'y') count++;
			}
			if (count > 0)
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


































	//FILE* file1 = fopen("myfileRead.txt", "r");
	//FILE* file2 = fopen("myfileRec.txt", "w");
	//// проверка на успех открытия файла
	//if (file1 != nullptr)
	//
	//{
	//	
	//	char buffer1[200];
	//	char buffer2[200];
	//	
	//	char hello [200];
	//	// цикл для чтения строк из текстового файла
	//	while (!feof(file1))
	//	{
	//		fputs("hello world", file1);
	//		fputs("\n123", file1);
	//		fputs("\nqwt", file1);

			
			//char glas[] = { 'a','o' ,'i','e' , 'u' , 'y' ,'A' ,'O' , 'I' , 'E' , 'U','Y' };
			//strcpy(buffer1, "");
			//// чтение целой строки из файла
			//fgets(buffer1, 200, file1);
			//cout << "data in first file " << buffer1 << endl;
		 //   if (strcmp(buffer1, glas) == 0)
			//	hello++;
			//char baffer2 = hello;
			//fputs(buffer2, file2);




			//int length, i, j, kol = 0;
			//char vowel[] = "AEIOUYaeiouy";
			//////функция считывает все введённые символы с пробелами до тех пор, пока не будет нажата клавиша Enter 
			//length = strlen(buffer1);
			//for (j = 0; j <= 5; j++) {
			//	for (i = 0; i <= length; i++)
			//		if (buffer1[i] == vowel[j])//сравниваем введённые элементы с заданными значениями строки
	    //*             fputs(buffer1, file2);

			
		




//		// закрытие файла
//		fclose(file1);
//		fclose(file2);
//
//	}
//	else
//	{
//		cout << "Error opening file!" << endl;
//	}
//}
