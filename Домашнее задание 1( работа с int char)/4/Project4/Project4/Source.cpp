#include <iostream>
using namespace std;
void main()
{
	//4. ������������ ������ 3 �����, ��������� ������� ������������ ����� � ������� �� �����

	int a = 0, b = 0, c = 0;
	//���� � �����
	cout << "Enter first number: ";
	cin >> a;
	cout << "Enter second number: ";
	cin >> b;
	cout << "Enter third number: ";
	cin >> c;
	//���� � ����� ������� �����, ������� ���
	if (a > b, a > c)
	{
		cout << "Bigest number = " << a << endl;
	}
	//���� b ����� ������� �����, ������� ���
	if (b > a, b > c)
	{
		cout << "Bigest number = " << b << endl;
	}
	//���� c ����� ������� �����, ������� ���
	if (c > b, c > a)
	{
		cout << "Bigest number = " << c << endl;
	}
}