#include <iostream>
#include <time.h>

using namespace std;

// 4. ��������� �������� �� ������� ������� ��� �������� ����� � ���� ��
//������ ������ � ������� ��� �� �����(������������ �������)


// ���������� ������� ���������� �������
void fill_array(int a, int b, int c[], int arr_size)
{
	for (int i = 0; i < arr_size; i++)
	{
		c[i] = rand() % (b - a + 1) + a;
	}
}
// ������ �������
void print_array(int c[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;
}
//������� ����
int Zero(int c[], int arr_size)
{
	int result1 = 0;
	
	for (int i = 0; i < arr_size; i++)
	{
		if (c[i] == 0) result1++;
	}
	return result1;
	
}
//������� �������� �����
int Odd_Numbers(int c[], int arr_size)
{
	int result = 0;
	
	for (int i = 0; i < arr_size; i++)
	{
		if (c[i] % 2 == 1)
			result++;
	}
	return result;
}

void main()
{
	
	srand(time(0));
	int arr_size = 10;
	cout << "Enter size of array: ";
	cin >> arr_size;
	
	// ���������� ������������� �������
	int* a = new int[arr_size];

	fill_array(0, 10, a, arr_size);
	print_array(a, arr_size);

	int size2 = Zero(a, arr_size);
	int size3 = Odd_Numbers(a, arr_size);
	// ���������� ������������� �������
	int* b = new int[size2,size3];
	
	// ����������� ������������� ��������� �� ������� ������� �� ������
	int k = 0;
	int q = 0;
	for (int i = 0; i < arr_size; i++)
	{
		if (a[i] == 0)
		{
			b[k] = a[i];
			k++;
		}
		if(a[i] % 2 == 1)
		{
			b[q] = a[i];
			q++;
		}
	}
	print_array(b, size3);
	// �������� ������������� �������
	delete[] b;

	// �������� ������������� �������
	delete[] a;
}

