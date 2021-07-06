#include <iostream>
#include <conio.h>


using namespace std;

int main()
{
	//3. Пользователь вводит строку. Программа заменяет все цифры на '!' и выводит строку на экран

	char s[80];
	cin.getline(s, 80);
	for (int i = 0; s[i] != 0; i++)
	{			
			 if (s[i] >= '0' && s[i] <= '9') s[i] = '!';
	}
	cout << "Non numeric characters : " << s << endl;
}