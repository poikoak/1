#include <iostream>
#include <conio.h>


using namespace std;

int main()
{
	//2. Пользователь вводит строку. Программа подсчитывает количество не цифровых символов.
	char s[80];
	cin.getline(s, 80);
		int count = 0;
		for (int i = 0; s[i] != 0; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
			count++;
		else if (s[i] >= 1 && s[i] <= 47 || s[i] >= 58 && s[i] <= 64 || s[i] >= 91 && s[i] <= 96 || s[i] >= 123 && s[i] <= 127 || s[i] >= 176 && s[i] <= 223)
			count++;
	}
	cout << "Non numeric characters : " << count << endl;
}