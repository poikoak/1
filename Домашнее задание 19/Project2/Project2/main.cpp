#include <iostream>
#include "Matrix.h"
using namespace std;
void main()
{
	Matrix matrix;
	matrix.print();
	Matrix matrix1(10,10);	
	matrix1.print();
	Matrix matrix2(3,3);
	matrix2.print();
	matrix1 = matrix2;
	matrix1.print();
	cout << (matrix1 == matrix2) << endl;
	cout << (matrix1 != matrix2) << endl;
	matrix1 + matrix2;
	matrix1.print();
}