#include <iostream>
#include <time.h>

using namespace std;

//2. ѕользователь вводит двумерный динамический массив, 
//программа находит сумму нечЄтных отрицательных элементов. (рекурсивна€ функци€)
void fill_array_keyboard(int** a, int row_count, int col_count)
	{
		for (int i = 0; i < row_count; i++)
		{
			// цикл по €чейкам строки
			for (int k = 0; k < col_count; k++)
			{
				cin >> a[i][k] ;
			}
			
		}
		cout << endl;
		
	}
int Odd_numbers(int** a, int row_count, int col_count)
{
	int result = 0;
	for (int i = 0; i < row_count; i++)
	{
		// цикл по €чейкам строки
		for (int k = 0; k < col_count; k++)
		{
			if (a[i][k] % 2 == -1)
				result++;
		}
	}
	return result;
}
int check(int** a, int result, int count, int n = 0)
{

	int res = 0;
	int x = result;
	if (n < count)
		res = check(a, count, n + 1);
	return (x < 0) ? res + x : res;
	
}
void main()
	{
	
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
		fill_array_keyboard(a, rows, col);				
		cout<<Odd_numbers(a, rows, col) << endl;
		cout << "sum of odd numbers" << endl;
		int rec = check(a, rows, col);
		/*cout << check(a, rows,col) << endl;*/
		cout << rec;
		for (int i = 0; i < rows; i++)
		{
			delete[] a[i];
		}

	delete[] a;
}
