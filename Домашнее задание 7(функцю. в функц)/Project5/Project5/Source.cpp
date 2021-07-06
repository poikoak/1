#include <iostream>
#include <time.h>

using namespace std;

//5. Пользователь вводит с клавиатуры размеры 2 динамических массивов и сами массивы. Программа
//объединяет эти массивы в третий динамический массив и выводит его на экран.

// заполнение массива с клавиатуры
void fill_array_keyboard(int c[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> c[i];
	}
}

// печать массива
void print_array(int c[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;
}


void main(int arr[])
{

	
	int arr_size1 = 5;
	int arr_size2= 5;
	cout << "Enter size of array 1: ";
	cin >> arr_size1;
	int* a = new int[arr_size1];
	fill_array_keyboard(a, arr_size1);
	

	cout << "Enter size of array 2: ";
	cin >> arr_size2;
	int* b = new int[arr_size2];
	fill_array_keyboard(b, arr_size2);


	cout << "Third_array: ";
	int size3= 10;
	int* c = new int[size3];
	int k = 0;
	for (int i = 0; i < arr_size1; i++)
	{

		c[k] = a[i];
		k++;
		
	}
	
	for (int i = 0; i < arr_size2; i++)
	{

		c[k] = b[i];
		k++;
		
	}
	print_array(c, size3);
	
	delete[] c;
	delete[] b;
	delete[] a;
}


