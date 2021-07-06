#include <iostream>
using namespace std;
// 2. Пользователь вводит числа, пока не введёт 0. Рекурсивная функция подсчитывает
//количество троек среди введенных чисел.
int count(int n)
{
	int a;	
	int res = 0;
	cin >> a;	
	if (a != 0)
	{		
		res = count(n + 1);
	}
	return (a == 3) ? res + 1 : res;
}

void main()
{
	char ch = 0;	
	int res = count(0);
	if (res == 0)
		cout << "there is no number 3, among the numbers" << endl;
	else if(res>0)
	cout << "Count of number 3 = " << res << endl;
}
