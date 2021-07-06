#include <iostream>
#include "conio.h"

using namespace std;

int line(const char s[], const char s2[], int size)
{
	//5. Функция принимает 2 строки и возвращает 1, если они равны, 0 - если они не равны (сравнение строк)
	for (size_t i = 0; i < size; i++)
	{
		if (s[i] == s2[i])
			return true;
		else
		{
			return false;
		}
	}
}
void main()
{
	char s[80];
	cout << "Enter first string: ";
	cin.getline(s, 80);

	char s2[80];
	cout << "Enter second string: ";
	cin.getline(s2, 80);
	if (line(s, s2, 80))
		cout << "1" << endl;
	else
		cout << "2" << endl;
}