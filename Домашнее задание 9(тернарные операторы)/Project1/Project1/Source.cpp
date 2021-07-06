#include <iostream>
using namespace std;
//1. Шаблонная функция принимает 2 одномерных массива и их размеры
//и возвращает максимум обоих массивов(тернарные операторы)

	
	template <typename T>
	void BiggestNumber(T a[], T b[], T size)
	{
		T max1 = 0;
		T max2 = 0;
		for (int i = 0; i < size; i++)
			
		{
			(max1 < a[i])? max1 = a[i]:0;
			(max2 < b[i])? max2 = b[i]:0;			
		}
		(max1 >= max2) ? cout<<"MAX number from first column = "<<max1 : cout << "MAX number from second column = " << max2;
		

	}
void main()
{
	int a[] = { 10, 2, 55, 4, 22};
	int b[] = { 1, 2, 3, 66, 44 };
	BiggestNumber(a,b, 5);
}
