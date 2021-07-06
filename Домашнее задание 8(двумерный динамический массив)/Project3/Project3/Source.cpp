#include <iostream>
#include <time.h>

using namespace std;
/*3. ‘ункци€ принимает двумерный динамический массив и копирует все нечЄтные числа в одномерный
динамический массив после чего результат выводитс€ на экран*/
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


void print_array(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void fill_matrix(int** a, int row_count, int col_count)
{
	// цикл по строкам
	for (int i = 0; i < row_count; i++)
	{
		// цикл по €чейкам строки
		for (int k = 0; k < col_count; k++)
		{
			a[i][k] = rand() % 100;
		}
	}
}

int Odd_numbers(int** a, int row_count, int col_count)
{
	int result = 0;
	for (int i = 0; i < row_count; i++)
	{
		// цикл по €чейкам строки
		for (int k = 0; k < col_count; k++)
		{
			if (a[i][k] % 2 == 1)
				result++;
		}
	}
	return result;
}


void main()
{
	srand(time(0));

	// ƒвумерные массивы

	// количество строк
	int rows;
	cout << "Enter number of rows: ";
	cin >> rows;

	// количество столбцов
	int col;
	cout << "Enter number of colums: ";
	cin >> col;

	// выделение пам€ти под массив указателей
	int** a = new int* [rows];

	// веделение пам€ти под строки
	for (int i = 0; i < rows; i++)
	{
		a[i] = new int[col];
	}

	fill_matrix(a, rows, col);
	print_matrix(a, rows, col);
	cout << "Matrix of odd numbers" << endl;
	Odd_numbers(a, rows, col);
	int size = Odd_numbers(a, rows, col);
	// объ€вление динамического массива
	int* b = new int[size];

	// копирование отрицательных элементов из первого массива во второй
	
	int q = 0;
	for (int i = 0; i < rows; i++)
	{
		// цикл по €чейкам строки
		for (int k = 0; k < col; k++)
			if (a[i][k] % 2 == 1)
			{
				b[q] = a[i][k];
				q++;
			}
	}
	
	print_array(b, size);
	// удаление динамического массива
	delete[] b;	
	for (int i = 0; i < rows; i++)
	{
		delete[] a[i];
	}
	delete[] a;

}

