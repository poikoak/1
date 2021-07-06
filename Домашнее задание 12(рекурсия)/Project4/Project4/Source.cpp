#include <iostream>

using namespace std;

// 4. Пользователь вводит 5 чисел, рекурсивная функция возвращает 1, если все числа идут в порядке
//возрастания, а иначе 0
int chek(int n)
{
	int a;
	cin >> a;
	int count = 0;
	if (n < 5)
	{
		count = chek(n + 1);
	}
	return (a + 1 >=n) ? count + 1 : count;
}
void main()
{
	int count = chek(1);
	if (count == 5)
	{
		cout << 0;
	}
	else
	{
		cout << 1;
	}
}
