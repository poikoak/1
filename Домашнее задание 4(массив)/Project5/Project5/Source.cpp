#include <iostream>
using namespace std;
void main()
{
	//������������ ������ ������ 3�4.��������� ������ ������� ������
	//� ��������� ������, ��������� ������� ������ �� �����
	
	int a[3][4];
	int i,k,tmp;

	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			cin >> a[i][k];		
			tmp = a[0][k];
			a[0][k] = a[ 2][k];
			a[2][k] = tmp;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 4; k++)
		{
			cout << "a[" << i << "][" << k << "] = " << a[i][k] << " ";
		}
		cout << endl;
	}
}