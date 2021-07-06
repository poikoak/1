#include <iostream>
#include <time.h>
using namespace std;
//4. Пользователь вводит размеры двумерного массива и сам массив.Программа меняет местами
//2 и 3 столбцы этого массива, после чего выводит массив на экран.
void print_matrix(int** a, int row, int col)
{
	cout << "Colums----->: " << endl;

	for (int i = 0; i < row; i++)
	{
	
		for (int k = 0; k < col; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}
}

void fill_matrix(int** a, int row, int col)
{

	for (int i = 0; i < row; i++)
	{
	
		for (int k = 0; k < col; k++)
		{
			a[i][k] = rand() % 100;
		}
	}
}


void change(int** a, int row, int col)
{
	int tmp;
	for (int i = 0; i < row; i++)
	{

		for (int k = 0; k < col; k++)
		{
			tmp = a[i][1];
			a[i][1] = a[i][2];
			a[i][2] = tmp;
			
		}
	}

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
	int** d = new int* [rows];	
	for (int i = 0; i < rows; i++)
	{
		d[i] = new int[colums];
	}

	fill_matrix(d, rows, colums);
	print_matrix(d, rows, colums);
	change(d, rows, colums);
	cout << "Changed colums----->: " << endl;
	print_matrix(d, rows, colums);

	for (int i = 0; i < rows; i++)
	{
		delete[] d[i];
	}


	delete[] d;
}