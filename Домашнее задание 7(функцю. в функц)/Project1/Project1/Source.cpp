#include <iostream>
#include <time.h>

using namespace std;
//1. Пользователь вводит диапазон случайных чисел и их количество.Программа выводит все
//числа на экран и подсчитывает их сумму, количество чётных и нечётных чисел.

void main()
{
	srand(time(0));
	int result = 0;
	int a, b,q, odd=0,even=0;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	for (int i = 0; i < 5; i++)
	{
		int q = rand() % (b - a + 1) + a;
		cout << q << endl;
		result += q;
		if (q % 2 == 1)
			odd++;
		else
		{
			even++;
		}
		
		
	}
	cout <<"Sum of numbers: "<<result << endl;
	cout << "EvenCount of numbers: " << even << endl;
	cout << "OddCount of numbers: " << odd << endl;
}

