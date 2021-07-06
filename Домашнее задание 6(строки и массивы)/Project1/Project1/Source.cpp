#include <iostream>

using namespace std;
//1. Функция принимает 3 числа и возвращает их произведение
// объявление функции (заголовок без тела)

void product(int a, int b, int c)
{
	cout << a * b * c << endl;
}

// точка входа в программу
void main()
{
	cout << "Product of 3 numbers = ",  product(5, 5, 5);
	
}
