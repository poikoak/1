#include "Matrix.h"
#include <iostream>

#include <fstream>
#include <string>

using namespace std;

void Matrix::Set_fill_matrix()
{

	for(int i = 0; i < rows; i++)
	{
		for (int k = 0; k < col; k++)
		{
			cin >> a[i][k];
		}
	}
	cout << endl;

}

void Matrix::SetmatrixROW(int rows)
{
	if (rows >= 0 && rows < 10)
	{
		this->rows = rows;
	}
}
int Matrix::GetmatrixROW()
{
	
	return rows;

}

 void Matrix::SetmatrixCOL(int col)
{
	if (col >= 0 && col < 10)
	{

		this->col = col;
	}
}
 int Matrix::GetmatrixCOL()
{
	return col;
}





int Matrix::Matrixq() 
{
	cout << "Constr" << endl;
	this-> a = new int* [rows];
	
	// веделение пам€ти под строки
	for (int i = 0; i < rows; i++)
	{
		a[i] = new int[col];


	}

	return 0;
}

Matrix::~Matrix()

{   // очистка пам€ти из-под строк
	for (int i = 0; i < rows; i++)
	{
		delete[] a[i];
	}

	// очистка пам€ти из-под массива указателей
	delete[] a;

	cout << "Destr" << endl;
}

void Matrix::print()
{
	for (int i = 0; i < rows; i++)
	{
		// цикл по €чейкам строки
		for (int k = 0; k < col; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}


}








void Matrix::operator() (int n, int m)
{
	for (int i = 0; i < rows; i++)
	{
		// цикл по €чейкам строки
		for (int k = 0; k < col; k++)
		{
			if (a[i][k] == n)
				a[i][k] = m;
		}
	}
}







void Matrix::Save(char filename[])
{
	FILE* file = fopen(filename, "w");
	if (file)
	{



			printf("Initial matrix: \n"); //вывод исходной матрицы на экран и в файл
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				printf("%5i", a[i][j]);
				fprintf(file, "%4d", a[i][j]);
				fprintf(file, "\n");
			}
			printf("\n");
		}
	}
	else
		cout << "no such file!" << endl;
	fclose(file);
}
void Matrix::Load(char filename[])
{
	string line;
	ifstream in(filename);
	if (in.is_open())
	{
		while (getline(in, line))
		{
			cout << line << endl;
		}
	}
	in.close();
}