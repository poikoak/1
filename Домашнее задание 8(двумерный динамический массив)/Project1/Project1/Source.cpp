#include <iostream>
#include <time.h>

using namespace std;
//1. ������������ ������ �������� ��������� ����� � ������� ���������� ������������� �������.
//��������� ��������� ������ ������� � �������� ���������
//� ������� �� �����, ��������� ����� �����.
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

void fill_matrix(int** a, int row_count, int col_count)
{

	srand(time(0));
	
	int q, b;
	cout << "Random numbers start from : ";
	cin >> q;
	cout << "Random numbers numbers end with : ";
	cin >> b;

	// ���� �� �������
	for (int i = 0; i < row_count; i++)
	{
		// ���� �� ������� ������
		for (int k = 0; k < col_count; k++)
		{
			a[i][k] = rand() % (b - q + 1) + q;
		}
	}
}
void Summ_matrix(int** a, int row_count, int col_count)
{
	int sum = 0;
	// ���� �� �������
	for (int i = 0; i < row_count; i++)
	{
		// ���� �� ������� ������
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
		// ��������� ������ ��� ������ ����������
		int** d = new int* [rows];
		// ��������� ������ ��� ������
		for (int i = 0; i < rows; i++)
		{
			d[i] = new int[col];
		}

		fill_matrix(d, rows, col);
		print_matrix(d, rows, col);
		Summ_matrix(d, rows, col);
		// ������� ������ ��-��� �����
		for (int i = 0; i < rows; i++)
		{
			delete[] d[i];
		}

		// ������� ������ ��-��� ������� ����������
		delete[] d;
}