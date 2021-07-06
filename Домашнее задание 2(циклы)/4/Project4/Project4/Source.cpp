#include <iostream>

using namespace std;
//4. Пользователь вводит 5 чисел, программа находит сумму минимального
//и максимального чисел из введенных и выводит на экран
void main() {
	int a = 0, max = 0, min=0;
	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		if (i == 0 || a > max) max = a;
		if (i == 0 || a < min) min = a;
		min + max;
	}
	cout << "max number= " << max << endl;
	cout << "min number= " << min << endl;
	cout << "Sum of numbers of min and max = " << min + max << endl;
}