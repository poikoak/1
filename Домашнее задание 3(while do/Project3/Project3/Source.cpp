#include <iostream>
using namespace std;
void main()
/*3. ������������ ������ ������ �� 5 �����, ��������� ����������� ��� ������������� ����� � 2 ����,
� ��� ������������� ����� ��������� �� 2 � ������� ������ �� �����*/
{
	int a[5];

	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
		if (a[i] < 0)
			(a[i] *= 2);
		if (a[i] > 0)
			(a[i] -= 2);
	}
	cout << "_________" <<endl;
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
}