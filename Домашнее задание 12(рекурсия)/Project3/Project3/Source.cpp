#include <iostream>
using namespace std;
// 3. ������������ ������ 5 �����, ����������� ������� ���������� 1, ���� ��� ����� �������������
//� ����� 0
int chek(int n)
{	
	int a;
	cin >> a;
	int i;
	int count = 0;
	if (n < 5)
	{
		count = chek(n + 1);
	}	
		return (a > 0) ? count + 1 : count;
}
void main()
{
	int count= chek(1);
	if (count==5)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
}
