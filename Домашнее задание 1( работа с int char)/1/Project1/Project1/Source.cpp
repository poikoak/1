#include <iostream>
using namespace std;
void main()
{
	//������������ ������ 4 �����, ��������� ������������ ���������� ����� ����� ��� � ������� �� �����
	int a = 0, b = 0, c = 0, d = 0, Q = 0;
	//���� � �����
	cout << "Enter first number: ";
	cin >> a;
	cout << "Enter second number: ";
	cin >> b;
	cout << "Enter third number: ";
	cin >> c;
	cout << "Enter fourth number: ";
	cin >> d;
	//������ ������� 
	if (a == 3) Q++;
	if (b == 3) Q++;
	if (c == 3) Q++;
	if (d == 3) Q++;
	{
		cout << "Numbers = " << Q << endl;
	}
	system("pause");
}