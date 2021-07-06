#include <iostream>
#include "conio.h"

using namespace std;

void main()
{
	//4. Пользователь вводит 2 строки, программа определяет равно ли у них количество гласных букв
	char s[80];
	cin.getline(s, 80);
	int vowels_count1 = 0;
	char s2[80];
	cin.getline(s2, 80);
	int vowels_count2 = 0;

	for (int i = 0; s[i] != 0; i++)
	{
		if (s[i] == 'a' || s[i] == 'o' || s[i] == 'i' || s[i] == 'e' || s[i] == 'u' || s[i] == 'y')
			vowels_count1++;
	}
	for (int i = 0; s2[i] != 0; i++)
	{
		if (s2[i] == 'a' || s2[i] == 'o' || s2[i] == 'i' || s2[i] == 'e' || s2[i] == 'u' || s2[i] == 'y')
			vowels_count2++;
	}
	if (vowels_count1 != vowels_count2)
	{
		cout << "Unequal number of vowels!" << endl;
	}
	else
	{
		cout << "Equal number of vowels!" << endl;
	}
}




