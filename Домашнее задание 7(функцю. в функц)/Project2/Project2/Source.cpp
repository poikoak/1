#include <iostream>
#include <time.h>

using namespace std;
//2. ‘ункци€ принимает массив чисел, мен€ет местами первую и последнюю €чейки массива и
//друга€ функци€ выводит массив на экран.


int Change(int a[], int size)
{
	
	int result = 0;
	int tmp;
	for (int i = 0; i < size; i++)
	{
		tmp = a[0];
		a[0] = a[6];
		a[6] = tmp;
	}

	return result;
}

void fill_array_keyboard(int a[], int size)
{
	cout << "Enter a numbers: " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> a[i];
	}
	
}
void print_array(int c[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;
}
void main()
{

	int a[7];
	fill_array_keyboard(a, 7);
	print_array(a, 7);
	Change(a, 7);
	print_array(a, 7);
}
	