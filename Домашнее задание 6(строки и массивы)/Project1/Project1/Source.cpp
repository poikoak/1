#include <iostream>

using namespace std;
//1. ������� ��������� 3 ����� � ���������� �� ������������
// ���������� ������� (��������� ��� ����)

void product(int a, int b, int c)
{
	cout << a * b * c << endl;
}

// ����� ����� � ���������
void main()
{
	cout << "Product of 3 numbers = ",  product(5, 5, 5);
	
}
