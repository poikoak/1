#include <iostream>
using namespace std;
void main()
/*5. ������������ ������ 2 ������� �� 4 �����, ��������� �������� �� ������� 
�������� ������� ������� ������� ������� ������� � ��������� ���������� � 3 ������, 
��� ������� ��������� �� �����.*/
{
	int a[4], b[4], q[4];
	cout << "first massive" << endl;
	for (int i = 0; i < 4; i++)
	{	
		cin >> a[i];
	}
	cout << "second massive" << endl;
	for (int i = 0; i < 4; i++)
	{	
		cin >> b[i];
	}
	cout << "third massive (first m. - second m.=third massive)" << endl;
	for (int i = 0; i < 4; i++)
	{
		q[i] = a[i] -= b[i];
		cout << q[i] << endl;
		
	}
	system("pause");
}