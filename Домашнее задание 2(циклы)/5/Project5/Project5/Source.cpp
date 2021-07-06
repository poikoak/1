#include <iostream>
using namespace std;
//5. Пользователь вводит 5 чисел, программа подсчитывает количество 
//положительных,отрицательных чисел и нулей и выводит на экран
void main() {
	int a = 0, pos = 0, neg = 0,zero=0;
	for (int i = 0; i < 5; i++)
	{
		cin >> a;
        if (a < 0) ++neg;
		if (a > 0) ++pos;
		if (a == 0) ++zero;
	}
	cout << "Possitive number= " << pos << endl;
	cout << "Negative number= " << neg << endl;
	cout << "Zero numbers= " << zero  << endl;
}