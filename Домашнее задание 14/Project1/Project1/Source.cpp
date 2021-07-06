#include <iostream>
using namespace std;

/*1. ������� ��������� ��������� ������������ ������ � �� ������� ���������� ������� 
��������������, ���������� ������� ����� � ���������� ������������� �����.
*/

//������� ������� ��������������
int Arifm(int** a, int row_count, int col_count, int& avr)
{
	
	for (int i = 0; i < row_count; i++)
	{
		// ���� �� ������� ������
		for (int k = 0; k < col_count; k++)
		{
			avr = avr + a[i][k];
				
		}
	}
	avr = avr / (row_count * col_count);
	return avr;
}
//������� ��� ������� �����
int Simple(int** a, int row_count, int col_count, int& pvr)
{
	
	for (int i = 0; i < row_count; i++)
	{
		// ���� �� ������� ������
		for (int k = 0; k < col_count; k++)
		{
			if (a[i][k] % 2 == 1)
				pvr++;
		}
	}
	return pvr;
}
//������� ��� ���������� �����
int Negative(int** a, int row_count, int col_count, int& neg)
{
	
	for (int i = 0; i < row_count; i++)
	{
		// ���� �� ������� ������
		for (int k = 0; k < col_count; k++)
		{
			if (a[i][k] < 0)
				neg++;
		}
	}
	return neg;
}

void main()
{
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

	int avr = 0;
	int pvr = 0;
	int neg = 0;

	//���� �������
	cout << "Enter an array: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k < col; k++)
		{
			cin >> a[i][k];
		}
	}
	cout << "\n";

	//����� �������
	cout << "Array is: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k < col; k++)
		{
			cout << a[i][k] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";

	//���������
	Arifm(a, rows, col, avr);
	Simple(a, rows, col, pvr);
	Negative(a, rows, col, neg);
	cout << "the average arithmetic = " << avr << endl;
	cout << "number of primes : " << pvr << endl;
	cout << "number of negative numbers : " << neg << endl;
	for (int i = 0; i < rows; i++)
	{
		delete[] a[i];
	}
	delete[] a;

	system("pause");
}