#include <iostream>
using namespace std;
void main()
{
	//2. Пользователь вводит 5 чисел, программа подсчитывает сумму положительных чисел и выводит на экран

	int a = 0, b = 0, c = 0, d = 0, q = 0, S = 0;
	//ввод с клавы
	cout << "Enter first number: ";
	cin >> a;
	cout << "Enter second number: ";
	cin >> b;
	cout << "Enter third number: ";
	cin >> c;
	cout << "Enter fourth number: ";
	cin >> d;
	cout << "Enter fifth number: ";
	cin >> q;
	if (0 < a)S = (S + a);

	if (0 < b)S = (S + b);

	if (0 < c)S = (S + c);

	if (0 < d)S = (S + d);

	if (0 < q)S = (S + q);

	{
		cout << "Sum of positive numbers = " << S << endl;
	}
}