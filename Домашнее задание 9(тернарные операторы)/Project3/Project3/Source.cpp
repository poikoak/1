#include <iostream>
#include <time.h>
using namespace std;

//3. Пользователь вводит размеры двумерного массива и сам массив.Программа находит максимальное число
//в строке и одновременно минимальное число в столбце, если такое существует в массиве.
void print_matrix(int** a, int row, int col)
{
	// цикл по строкам
	for (int i = 0; i < row; i++)
	{
		// цикл по ячейкам строки
		for (int k = 0; k < col; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}
}

void fill_matrix(int** a, int row, int col)
{
	// цикл по строкам
	for (int i = 0; i < row; i++)
	{
		// цикл по ячейкам строки
		for (int k = 0; k < col; k++)
		{
			a[i][k] = rand() % 100;
		}
	}
}

bool min_number(int** a, int colums, int min, int Rindex)

{
		for (int i = 0; i < colums; i++)
		{
			if (min > a[Rindex][i])
				return false;
		}
		return true;
}

bool max_number(int** a, int rows, int max, int Cindex)
{
	for (int i = 0; i < rows; i++)
	{
		if (max < a[i][Cindex])
			return false;
	}
	return true;
}

void main()
{
	srand(time(0));
	int rows;
	cout << "Enter number of rows: ";
	cin >> rows;
	int colums;
	cout << "Enter number of colums: ";
	cin >> colums;
	int** a = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		a[i] = new int[colums];
	}

	fill_matrix(a, rows, colums);
	print_matrix(a, rows, colums);
	for (int i = 0; i < rows; i++)
	{
	for (int k = 0; k < colums; k++)
		{
			if (max_number(a, rows, a[i][k], k) && min_number(a, colums, a[i][k], i))
				cout <<"Maximum number in a row and at the same time the minimum number in a column = "<< a[i][k] << endl;
		}
	
	}








	for (int i = 0; i < rows; i++)
	{
		delete[] a[i];
	}

	
	delete[] a;
}
