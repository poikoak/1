#include <iostream>

using namespace std;

// 1. Пользователь вводит массив из 5 чисел, рекурсивная функция выясняет, все ли числа в массиве
//делятся на 2 и на 3 без остатка. (рекурсивная функция)
void fill(int arr[],int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	cout << " ";
}
int check(int arr[], int count, int n = 0)
{

	int res = 0;
	if (n < count)
		res = check(arr, count, n + 1);
	return res + ((arr[n] % 2 == 0 && arr[n] % 3 == 0) ? 1 : 0);
}
void main()
{
	int arr_size = 5;
	int* a = new int[arr_size];
	cout << "enter 5 digits" << endl;
	fill(a, arr_size);
	cout << (check(a, 5) ) ? true : false;
	delete[] a;

}
