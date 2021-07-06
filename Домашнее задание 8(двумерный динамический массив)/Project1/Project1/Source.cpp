#include <iostream>
#include <time.h>

using namespace std;
//1. ѕользователь вводит диапазон случайных чисел и размеры двумерного динамического массива.
//ѕрограмма заполн€ет массив числами в заданном диапазоне
//и выводит на экран, подсчитав общую сумму.
void print_matrix(int** a, int row_count, int col_count)
{
	// цикл по строкам
	for (int i = 0; i < row_count; i++)
	{
		// цикл по €чейкам строки
		for (int k = 0; k < col_count; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}
}

void fill_matrix(int** a, int row_count, int col_count)
{

	srand(time(0));
	
	int q, b;
	cout << "Random numbers start from : ";
	cin >> q;
	cout << "Random numbers numbers end with : ";
	cin >> b;

	// цикл по строкам
	for (int i = 0; i < row_count; i++)
	{
		// цикл по €чейкам строки
		for (int k = 0; k < col_count; k++)
		{
			a[i][k] = rand() % (b - q + 1) + q;
		}
	}
}
void Summ_matrix(int** a, int row_count, int col_count)
{
	int sum = 0;
	// цикл по строкам
	for (int i = 0; i < row_count; i++)
	{
		// цикл по €чейкам строки
		for (int k = 0; k < col_count; k++)
		{
			if (sum += a[i][k]);
		}
		
	}
	cout << "Sum of the  colums = " << sum << endl;
}
void main()
{
		srand(time(0));
		int rows;
		int col;
		cout << "Enter number of rows: ";
		cin >> rows;	
		cout << "Enter number of colums: ";
		cin >> col;
		// выделение пам€ти под массив указателей
		int** d = new int* [rows];
		// веделение пам€ти под строки
		for (int i = 0; i < rows; i++)
		{
			d[i] = new int[col];
		}

		fill_matrix(d, rows, col);
		print_matrix(d, rows, col);
		Summ_matrix(d, rows, col);
		// очистка пам€ти из-под строк
		for (int i = 0; i < rows; i++)
		{
			delete[] d[i];
		}

		// очистка пам€ти из-под массива указателей
		delete[] d;
}