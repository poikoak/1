#include <iostream>
#include <conio.h>


using namespace std;

int main()
{
	/*1. ������������ ������ �������, ���� �� ����� ESC.
		��������� ������������ ����� ���� ��������� �����.*/


	int result = 0;
	char ch = 0;
	do
	 {
		ch = _getch();
		cout<<ch<< endl;
		if (ch >= '0' && ch <= '9')
			result += ch - 48;
	} while (ch != 27);	
	cout << "SSum of numbers = " << result << endl;
	//��� � �� ����� ������ �� ����� ������ ������ ����� � " SSum of numbers = ".
	//���������� ��� ���� �� �������� S ������� " um of numbers = "
}