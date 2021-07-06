#include <iostream>
using namespace std;
void main()
{
	//4. Пользователь вводит 3 числа, программа находит максимальное число и выводит на экран

	int a = 0, b = 0, c = 0;
	//ввод с клавы
	cout << "Enter first number: ";
	cin >> a;
	cout << "Enter second number: ";
	cin >> b;
	cout << "Enter third number: ";
	cin >> c;
	//Если а самое большое число, выводим его
	if (a > b, a > c)
	{
		cout << "Bigest number = " << a << endl;
	}
	//Если b самое большое число, выводим его
	if (b > a, b > c)
	{
		cout << "Bigest number = " << b << endl;
	}
	//Если c самое большое число, выводим его
	if (c > b, c > a)
	{
		cout << "Bigest number = " << c << endl;
	}
}