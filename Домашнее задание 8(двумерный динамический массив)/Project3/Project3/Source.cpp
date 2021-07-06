#include <iostream>
#include <time.h>

using namespace std;
/*3. ������� ��������� ��������� ������������ ������ � �������� ��� �������� ����� � ����������
������������ ������ ����� ���� ��������� ��������� �� �����*/
void print_matrix(int** a, int row_count, int col_count)
{
	// ���� �� �������
	for (int i = 0; i < row_count; i++)
	{
		// ���� �� ������� ������
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
	// ���� �� �������
	for (int i = 0; i < row_count; i++)
	{
		// ���� �� ������� ������
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
		// ���� �� ������� ������
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

	// ��������� �������

	// ���������� �����
	int rows;
	cout << "Enter number of rows: ";
	cin >> rows;

	// ���������� ��������
	int col;
	cout << "Enter number of colums: ";
	cin >> col;

	// ��������� ������ ��� ������ ����������
	int** a = new int* [rows];

	// ��������� ������ ��� ������
	for (int i = 0; i < rows; i++)
	{
		a[i] = new int[col];
	}

	fill_matrix(a, rows, col);
	print_matrix(a, rows, col);
	cout << "Matrix of odd numbers" << endl;
	Odd_numbers(a, rows, col);
	int size = Odd_numbers(a, rows, col);
	// ���������� ������������� �������
	int* b = new int[size];

	// ����������� ������������� ��������� �� ������� ������� �� ������
	
	int q = 0;
	for (int i = 0; i < rows; i++)
	{
		// ���� �� ������� ������
		for (int k = 0; k < col; k++)
			if (a[i][k] % 2 == 1)
			{
				b[q] = a[i][k];
				q++;
			}
	}
	
	print_array(b, size);
	// �������� ������������� �������
	delete[] b;	
	for (int i = 0; i < rows; i++)
	{
		delete[] a[i];
	}
	delete[] a;

}

