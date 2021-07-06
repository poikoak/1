#include <iostream>
#include <windows.h>

using namespace std;

void main()
{
	//2. Пользователь вводит массив 3Х3. Программа находит сумму элементов каждого столбца
	const int width = 3;
	const int height = 3;

	int a[height][width];

	int sum1=0,sum2=0,sum3=0;

	for (int i = 0; i < height; i++)
	{
		for (int k = 0; k < width; k++)
		{
			cin >> a[i][k];
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
		if (sum1 += a[i][0]);
		if (sum2 += a[i][1]);
		if (sum3 += a[i][2]);
	}
	

	cout << "Sum of the 1 colum = " << sum1 << endl;
	cout << "Sum of the 2 colum = " << sum2 << endl;
	cout << "Sum of the 3 colum = " << sum3 << endl;
}