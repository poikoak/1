#include <iostream>

using namespace std;
//1. ������������ ������ ������ �� ��� ���, ���� ��
//����� ����� "exit".��������� ��������� ���
//��������� ������ � ���� text.txt, ����� "exit" �� �����������.



int main()
{
	FILE* file = fopen("file.txt", "w");
	
	if (file != nullptr)
	{
	
		char str[80];
		char b[80];
		char exit[] = "exit";
		
			
		
			do
			{
				cin.getline(str, 80);
				strcpy(b, str);
				if (strcmp (b,exit) == 0) 
					strcpy(b, "");
				fputs(b, file);
			} while (strcmp(str, exit) );
		
		
		
		
		

		
		fclose(file);
	}
	else
	{
		cout << "Error opening file!" << endl;
	}
}



