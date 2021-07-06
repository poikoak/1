#include <iostream>
using namespace std;
void main()
{
//1. Пользователь вводит массив 3Х3. Программа находит максимальное 
//отрицательное число и минимальное положительное и выводит их на экран
	const int width = 3;
	const int height = 3;

	int a[height][width];

	int maxneg = 0,min;

	for (int i = 0; i < height; i++)
	{
		for (int k = 0; k < width; k++)
		{
			cin >> a[i][k];
			min = a[i][k];
			for (int i = 0; i < height; i++)
			{
				for (int k = 0; k < width; k++)
				{
					if (a[i][k] > 0 && a[i][k] < min)
						min = a[i][k];

				}
			}
		}
	}

		for (int i = 0; i < height; i++)
	{
		for (int k = 0; k < width; k++)
		{
			cout << "a[" << i << "][" << k << "] = " << a[i][k] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < height; i++)
	{
		for (int k = 0; k < width; k++)
		{
			if (a[i][k] < maxneg) maxneg = a[i][k];
			
		}
	}
	cout <<"MAX from neg = " << maxneg;
	cout << endl;
	cout << "MIN from possitive = " << min;
	cout << endl;
	
}