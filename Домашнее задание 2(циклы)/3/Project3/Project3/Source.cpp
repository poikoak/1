#include <iostream>

using namespace std;
//3. Пользователь вводит 5 чисел, программа находит максимальное из них
void main() {
	int a=0, max = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		if (i == 0 || a > max) max = a;
	}
	cout << "max number= " << max << endl;
}