#include <iostream>
#include <time.h>

using namespace std;
//2. ������� ��������� 2 ��������� ������������ ������� � �� ������� � ���������� ��
//�����������. (�� / ���)
int Array_Comparison(int** a, int row_count1, int col_count1, int** b, int row_count2, int col_count2)
{
	int result = 0;
	if (row_count1 != row_count2 || col_count1 != col_count2)
		result = false;
	for (int i = 0; i < row_count1; i++)
	{
		// ���� �� ������� ������
		for (int k = 0; k < col_count1; k++)
			if (a[i][k] == b[i][k])
			{
				result = true;
			}
			else result = false;
	}
	if (result == true)
		cout << "Yes" << endl;
	else cout << "No" << endl;
	return result;
}



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
void fill_array_keyboard(int** a, int row_count, int col_count)
{
	for (int i = 0; i < row_count; i++)
	{
		for (int k = 0; k < col_count; k++)
		{
			cin >> a[i][k];
		}
	}
	cout << endl;
}
void main()
{
	//������ ������
	int rows1;
	cout << "Enter number of rows: ";
	cin >> rows1;

	// ���������� ��������
	int cols1;
	cout << "Enter number of cols: ";
	cin >> cols1;

	// ��������� ������ ��� ������ ����������
	int** d = new int* [rows1];

	// ��������� ������ ��� ������
	for (int i = 0; i < rows1; i++)
	{
		d[i] = new int[cols1];
	}

	fill_array_keyboard(d, rows1, cols1);
	cout << "First massive " << endl;
	print_matrix(d, rows1, cols1);

	//*******************************************************************************
	//������ ������
	int rows2;
	cout << "Enter number of rows: ";
	cin >> rows2;

	// ���������� ��������
	int cols2;
	cout << "Enter number of cols: ";
	cin >> cols2;

	// ��������� ������ ��� ������ ����������
	int** q = new int* [rows2];

	// ��������� ������ ��� ������
	for (int i = 0; i < rows2; i++)
	{
		q[i] = new int[cols2];
	}

	fill_array_keyboard(q, rows2, cols2);
	cout << "Second massive " << endl;
	print_matrix(q, rows2, cols2);
	cout << endl;
	Array_Comparison(d, rows1, cols1,q, rows2, cols2); 
	//������� ������
	for (int i = 0; i < rows1; i++)
	{
		delete[] d[i];
	}


	delete[] d;

	for (int i = 0; i < rows2; i++)
	{
		delete[] q[i];
	}


	delete[] q;
}