#include <iostream>
#include "Matrix.h"

using namespace std;

//19.2. ��� ������ Matrix(��������� ������������ ������) �������� ��������� ������ :
//-Copy constr
//- operator =
//-operator ==, !=
//-operator+(int n) - ���������� n �� ���� ������ �������
//- operator+(Matrix m) - ���������� 2 ������� �����������, ���� ������� �����

void main() 
{
	Matrix m1;
	m1.Print();
	Matrix m2(5, 4);
	m2.Print();
	Matrix m3(5, 4);
	m3.Print();

	m2 + m3;
	m2.Print();
}