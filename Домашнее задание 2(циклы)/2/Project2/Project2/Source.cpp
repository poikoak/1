#include <iostream>

using namespace std;

void main()
//2. Пользователь вводит 5 чисел, программа подсчитывает сумму
//чётных чисел и выводит на экран
{
	int a = 0, n = 0,result=0;
	for (int i = 0; i < 5; ++i)
	{
			cin >> a;
		//находим четные числа и посчитываем сумму
		if (a % 2==0 )
		{
			result += a;
		}
	}
	cout << "Sum of numbers = " << result << endl; 
}

