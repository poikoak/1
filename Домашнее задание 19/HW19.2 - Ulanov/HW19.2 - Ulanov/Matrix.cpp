#include <iostream>
#include "Matrix.h"

using namespace std;

void Matrix::FillMatrix()
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t k = 0; k < columns; k++)
		{
			m[i][k] = rand() % 10;
		}
	}
}

Matrix::Matrix()
{
	rows = rand() % 10 + 2;
	columns = rand() % 10 + 2;
	m = new int* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		m[i] = new int[columns];
	}
	FillMatrix();
}

Matrix::Matrix(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
	m = new int* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		m[i] = new int[columns];
	}
	FillMatrix();
}

Matrix::~Matrix()
{
	delete[] m;
}

void Matrix::Print()
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t k = 0; k < columns; k++)
		{
			cout << m[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int& Matrix::operator() (int rows, int columns)
{

	if (rows <= this->rows && columns <= this->columns)
	{
		return m[rows][columns];
	}
	return m[0][0];
}

void Matrix::Save(char filename[], int rows, int columns)
{
	FILE* file = fopen(filename, "wb");
	if (file != nullptr)
	{
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t k = 0; k < columns; k++)
			{
				fprintf(file, "%3d", m[i][k]);
			}

			fprintf(file, "\n");
		};
		fclose(file);
		cout << endl;
	}
	else cout << "!Error saving file." << endl;
}

void Matrix::Load(char filename[], int rows, int columns)
{
	FILE* file = fopen(filename, "rb");
	if (file != nullptr)
	{
		fseek(file, 0, SEEK_END);
		size_t FileSize = ftell(file);
		fseek(file, 0, SEEK_SET);
		char* buffer = new char[FileSize];
		fread(buffer, sizeof(char), FileSize, file);
		fclose(file);
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t k = 0; k < columns; k++)
			{
				printf("%3i", m[i][k]);
			}
			printf("\n");
		}
		cout << endl;
		delete[] buffer;
	}
	else cout << "!Error opening file." << endl;
}

Matrix::Matrix(const Matrix& source)
{
	cout << "Copy Constr" << endl;
	this->rows = source.rows;
	this->columns = source.columns;
	m = new int*[rows];

	// поэлементное копирование двумерных массивов
	for (size_t i = 0; i < rows; i++)
	{
		m[i] = source.m[i];
	}
}

Matrix& Matrix::operator = (const Matrix& source)
{
	cout << "Operator =" << endl;
	if (rows != source.rows)
	{
		delete[] m;
		m = new int*[source.rows];
		rows = source.rows;
		columns = source.columns;
	}

	for (size_t i = 0; i < rows; i++)
	{
		m[i] = source.m[i];
	}

	return *this;
}

bool Matrix::operator==(Matrix& source)
{
	if (rows != source.rows && columns != source.columns)
	return false;

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t k = 0; k < columns; k++)
		{
			if (m[i][k] != source.m[i][k])
				return false;
		}
	}

	return true;
}

bool Matrix::operator!=(Matrix& source)
{
	if (rows != source.rows && columns != source.columns)
	return true;

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t k = 0; k < columns; k++)
		{
			if (m[i][k] != source.m[i][k])
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
		for (size_t k = 0; k < columns; k++)
		{
			m[i][k] = m[i][k] + n;
		}
	}

	return *this;
}

Matrix& Matrix::operator+(Matrix& source)
{
	if (rows == source.rows && columns == source.columns)
	{
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t k = 0; k < columns; k++)
			{
				m[i][k] = m[i][k] + source.m[i][k];
			}
		}
	}
	
	return *this;
}
