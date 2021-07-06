#include <iostream>
#include "Matrix.h"

using namespace std;

//19.2. Для класса Matrix(двумерный динамический массив) добавить следующие методы :
//-Copy constr
//- operator =
//-operator ==, !=
//-operator+(int n) - прибавляет n ко всем числам матрицы
//- operator+(Matrix m) - складывает 2 матрицы поэлементно, если размеры равны

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