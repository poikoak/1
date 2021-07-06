#include <iostream>
#include <time.h>
using namespace std;
//2. Шаблонная функция принимает одномерный массив и размер и выводит на экран 2 самых
//больших числа в массиве(тернарные операторы)
template <typename T>
void TwoBiggestNumb(T a[], T size)
{
	T max1 = a[0];
	T max2 = a[0];
	for (int i = 0; i < size; i++)

	{
		(max1 < a[i]) ? max1 = a[i] : 0;

	}

	for (int i = 0; i < size; i++)

	{
		(max2 < a[i] && a[i] < max1 && max1 != a[i]) ? max2 = a[i] : 0;

	}
	cout << "MAX number from first column = " << max1 << endl;
	cout << "MAX number from first column = " << max2 << endl;
}
	
void main()
{
	int a[] = { 10, 2, 39, 4, 54 };
	TwoBiggestNumb(a, 5);
}