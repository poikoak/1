#include <iostream>

using namespace std;

void main()
//2. ������������ ������ 5 �����, ��������� ������������ �����
//������ ����� � ������� �� �����
{
	int a = 0, n = 0,result=0;
	for (int i = 0; i < 5; ++i)
	{
			cin >> a;
		//������� ������ ����� � ����������� �����
		if (a % 2==0 )
		{
			result += a;
		}
	}
	cout << "Sum of numbers = " << result << endl; 
}

