#include <iostream>

using namespace std;
void main()
//1. ������������ ������ �����, ���� �� ����� �� ����� ������ 20. ��������� ��������� ������������
//������������� �����.������ ��� ������ ����� while ��� do..while

{
	int a=1, sum = 0, s=1;
	do 
	{
		cin >> a;
		if (a > 0) s *= a;
			sum += a; 
	} 
	while (sum < 20);
	
	cout << "Sum = " << sum << endl;
	cout << "Sum of pos = " << s << endl;
		system("pause");
		//�������� ����������� �������� ����� ����� �������� ���
    }
	

	
	