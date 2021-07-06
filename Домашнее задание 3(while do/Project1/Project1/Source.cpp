#include <iostream>

using namespace std;
void main()
//1. Пользователь вводит числа, пока их сумма не будет больше 20. Программа вычисляет произведение
//положительных чисел.Решить при помощи цикла while или do..while

{
	int a=1, sum = 0, s=1;
	do 
	{
		cin >> a;
		if (a > 0) s *= a;
			sum += a; 
	} 
	while (sum < 20);
	
	cout << "Sum = " << sum << endl;
	cout << "Sum of pos = " << s << endl;
		system("pause");
		//пришлось внимательно почитать книгу чтобы написать код
    }
	

	
	