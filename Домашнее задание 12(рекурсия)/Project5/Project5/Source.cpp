#include <iostream>
using namespace std;
//5. ������������ ������ 5 �����, ����������� ������� ���������� 1, ���� ��� ����� ��������
//��������, � ����� 0 (��������� �������� ���� ����� ������� �����������)
int chek(int n)
{
	if (n > 1)
	{		
		for (int i = 2; i < n; i++)
			if (n % i == 0) 
				return false;	
		return true;
	}
}
int simple(int n)
{

	int a;
	cin >> a;
	int count = 0;
	if (n < 5)
	{
		count = simple(n + 1);
	}

	return (chek(a) == true) ? count + 1 : count;
}
void main()
{
	

	int count = simple(1);
	if (count == 5)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}


}
