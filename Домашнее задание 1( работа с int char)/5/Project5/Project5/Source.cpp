#include <iostream>
using namespace std;
void main()
{
	//5. ѕользователь вводит 5 чисел, программа подсчитывает количество положительных, отрицательных чисел и нулей и выводит на экран

	int a = 0, b = 0, c = 0, d = 0, q = 0, S = 0, F = 0, K = 0;
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
	//находим положительные
	if (a > 0) S++;
	if (b > 0) S++;
	if (c > 0) S++;
	if (d > 0) S++;
	if (q > 0) S++;
	{
		cout << "Sum of positive numbers = " << S << endl;
	}
	//находим негативные
	if (a < 0) F++;
	if (b < 0) F++;
	if (c < 0) F++;
	if (d < 0) F++;
	if (q < 0) F++;
	{
		cout << "Sum of negative numbers = " << F << endl;
	}
	//находим нули
	if (a == 0) K++;
	if (b == 0) K++;
	if (c == 0) K++;
	if (d == 0) K++;
	if (q == 0) K++;
	{
		cout << "Sum of zero numbers = " << K << endl;
	}
}