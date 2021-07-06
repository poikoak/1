#include <iostream>
using namespace std;
void main()
/*4. Пользователь вводит 2 массива из 4 чисел, программа выясняет, 
равны ли суммы элементов этих массивов(YES / NO)*/

{
	int a[4], b[4], sumA=0, sumB=0;

	for (int i = 0; i < 4; i++)
	{
		cin >> a[i];
		sumA += a[i];
	}
	cout << "_________" << endl;
	for (int i = 0; i < 4; i++)
	{
		cin >> b[i];
		sumB += b[i];
	}
	cout << "_________" << endl;
	if (sumA == sumB)
	{
		cout << "YES, equal " << endl;
		system("pause");
	}
	else
	{
		cout << "No, not equal" << endl;
		system("pause");
	}

	
	
}