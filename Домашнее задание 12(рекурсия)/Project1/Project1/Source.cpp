#include <iostream>

using namespace std;

//1. ������������ ������ 5 �����, ����������� ������� ������������ ����� ������������� �����.
int count(int n)
{
	
	int a;	
	int res = 0;	
	cin >> a;	
	if (n < 5)
	{		
		res = count(n + 1);
	}
	return (a < 0) ? res + a : res;
}



void main()
{

	int res = count(1);
	cout << "Sum of negative numbers = " << res << endl;
	
}
