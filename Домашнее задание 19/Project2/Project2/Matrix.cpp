#include "Matrix.h"
#include <iostream>
using namespace std;

void Matrix::Set_fill_matrix()
{

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t k = 0; k < col; k++)
		{
			a[i][k] = rand() % 10;
		}
	}

}

Matrix::Matrix()
{
	rows = 3;
	col = 3;
	a = new int* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		a[i] = new int[col];
	}
	Set_fill_matrix();
}
 Matrix::Matrix(int rows,int col) 
{
	 this->rows = rows;
	 this->col = col;
	cout << "Constr" << endl;
	this-> a = new int* [rows];
	
	// веделение памяти под строки
	for (int i = 0; i < rows; i++)
	{
		a[i] = new int[col];


	}

	Set_fill_matrix();
	
}

Matrix::~Matrix()

{   // очистка памяти из-под строк
	for (int i = 0; i < rows; i++)
	{
		delete[] a[i];
	}

	// очистка памяти из-под массива указателей
	delete[] a;

	cout << "Destr" << endl;
}

void Matrix::print()
{
	for (int i = 0; i < rows; i++)
	{
		// цикл по ячейкам строки
		for (int k = 0; k < col; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}


}

Matrix::Matrix(const Matrix& source)
{

	cout << "COPY" << endl;
	this->rows = source.rows;
	this->col = source.col;
	this->a = new int* [rows];

	// веделение памяти под строки
	for (int i = 0; i < rows; i++)
	{
		a[i] = new int[col];


	}
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t k = 0; k < col; k++)
		{
			a[i][k] = source.a[i][k];
		}
	}

}

Matrix& Matrix::operator = (const Matrix& source)
{
	cout << "Operator =" << endl;
	if (rows != source.rows)
	{
		delete[] a;
		a = new int* [source.rows];
		rows = source.rows;
		col = source.col;
	}

	for (size_t i = 0; i < rows; i++)
	{
		a[i] = source.a[i];
	}

	return *this;
}

bool Matrix::operator==(Matrix& source)
{
	if (rows != source.rows && col != source.col)
		return false;

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t k = 0; k < col; k++)
		{
			if (a[i][k] != source.a[i][k])
				return false;
		}
	}

	return true;
}

bool Matrix::operator!=(Matrix& source)
{
	if (rows != source.rows && col != source.col)
		return true;

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t k = 0; k < col; k++)
		{
			if (a[i][k] != source.a[i][k])
				return true;
		}
	}

	return false;
}

Matrix& Matrix::operator+(int n)
{
	cout << "Operator +(int n)" << endl;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t k = 0; k < col; k++)
		{
			a[i][k] = a[i][k] + n;
		}
	}

	return *this;
}

Matrix& Matrix::operator+(Matrix& source)
{
	if (rows == source.rows && col == source.col)
	{
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t k = 0; k < col; k++)
			{
				a[i][k] = a[i][k] + source.a[i][k];
			}
		}
	}

	return *this;
}
