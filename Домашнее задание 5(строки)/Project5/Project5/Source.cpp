#include <iostream>
#include "conio.h"

using namespace std;

void main()
{
	//5. Пользователь вводит строку, программа меняет местами первый и последний символы и
	//выводит строку на экран

	char s[80];
	cin.getline(s, 80);
	cout<<" Before swap:  " << s << endl;
	int len = strlen(s);
	int temp = s[0];
	s[0] = s[len - 1];
	s[len - 1] = temp;
	cout << " After swap:  " << s << endl;

}