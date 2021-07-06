#include <iostream>
using namespace std;
void main()
{
	//Пользователь вводит 2 массива 2Х2. Если произведение всех чисел 1 массива равно
	//сумме всех чисел 2 массива, то программа пишет "YES", иначе "NO"
	const int width = 2;
	const int height = 2;
	int pro1 = 1, pro2 = 1;
	
	int a[height][width];
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
			pro1 *= a[i][k];
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
	for (int q = 0; q < height; q++)
	{
		for (int w = 0; w < width; w++)
		{
			cin >> a[q][w];
					
		}
	}
	for (int q = 0; q < height; q++)
	{
		for (int w = 0; w < width; w++)
		{
			pro2 *= a[q][w];
		}
	}
	for (int q = 0; q < height; q++)
	{
		for (int w = 0; w < width; w++)
		{
			cout << "a[" << q << "][" << w << "] = " << a[q][w] << " ";
		}
		cout << endl;
	}
	if (pro1 == pro2)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}












