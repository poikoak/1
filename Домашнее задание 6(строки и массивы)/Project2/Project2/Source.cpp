#include <iostream>
using namespace std;
//2. Функция принимает массив, размер массива и возвращает сумму 
//отрицательных элементов

int Findsum(int a[], int size)
{
	int result=0;
	for (int i = 0; i < size; i++)
	{
		if (a[i] < 0)
			result += a[i];
		}
	return result;
}


void main()
{
	int b[] = { -1, -2, 3, 4, 5 };
	cout << "sum of array: " << Findsum(b, 5) << endl;
}
