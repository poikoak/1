#include <iostream>
using namespace std;
void main()
{
	//3. ������������ ������ ������ 3�4.��������� ������ ��� 3 �� 5, 
	//� ��� 5 �� 3 � ������� ������ �� �����
	const int width = 3;
	const int height = 4;
	int a[height][width];
	int five = 5, three = 3;
	for (int i = 0; i < height; i++)
	{
		for (int k = 0; k < width; k++)
		{
			cin >> a[i][k];
			if (a[i][k] == 3)a[i][k] = five;
			else
			{
				if (a[i][k] == 5) a[i][k] = three;
			}
		}
	}
	for (int i = 0; i < height; i++)
	{
		for (int k = 0; k < width; k++)
		{
			cout << "a[" << i << "][" << k << "] = " << a[i][k] << " ";
		}
		cout << endl;
	}
}