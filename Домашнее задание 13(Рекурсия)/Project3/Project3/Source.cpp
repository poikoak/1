#include <iostream>
#include "conio.h"
#include <string> 
using namespace std;

//3. ����������� ������� ��������� ������ � ����� � ������������ ������� ��� ����� �����������
//� ������.



int count_chars(const char* string, char s) 
{
	return *string ? count_chars(string + 1, s) + (s == *string) : 0;
}

int main()
{


	char string[] = "123qqwe345asd";
	char s = 'q';
	cout<< count_chars(string,s)<<endl;


	

}