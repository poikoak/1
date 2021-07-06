#include <iostream>

using namespace std;

void main()
//2. Пользователь вводит массив из 5 чисел, программа проверяет, все ли они положительные (YES/NO)

{
	int a[5], i = 0;

	cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
	
	
		if (a[i] > 0)
		{
		cout << "YES all positive " << endl;
		system("pause");
	    } else
		{
			cout << "NO, have a negative number " << endl;
			system("pause");
	    }
		
}

    
	
	
	


