#include <iostream>
#include <time.h>

using namespace std;

/*4. ‘ункци€ принимает двумерный динамический массив и находит минимум, максимум, 
выводит их на экран, а потом мен€ет их местами в массиве и выводит массив на экран.*/
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

void print_max_min(int** a, int row_count, int col_count)
{
	//находим минимум и максимум
	int max;
	max = a[0][0];
	int  min;
	min = a[0][0];
	for (int i = 0; i < row_count; i++)
	{
		// цикл по €чейкам строки
		for (int k = 0; k < col_count; k++)
		{

			if (max < a[i][k]) max = a[i][k];
			if (min > a[i][k]) min = a[i][k];
		}

	}
	cout << "max number = " << max << endl;	
	cout << "min number = " << min << endl;
	//мен€ем их местами
	for (int i = 0; i < row_count; i++)
	{
		// цикл по €чейкам строки
		for (int k = 0; k < col_count; k++)
		{

			if (a[i][k] == min) a[i][k] = max;
			else
			if (a[i][k] == max) a[i][k] = min;
		}

	}
	cout << "Changed Matrix: " << endl;

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


void main()
{
	srand(time(0));
	// количество строк
	//int min, max;
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
	print_max_min(a, rows, col);
	print_matrix(a, rows, col);
	cout << endl;
	// очистка пам€ти из-под строк
	for (int i = 0; i < rows; i++)
	{
		delete[] a[i];
	}

	// очистка пам€ти из-под массива указателей
	delete[] a;
}