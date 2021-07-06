#include <iostream>
#include <conio.h>


using namespace std;

int main()
{
	/*1. Пользователь вводит символы, пока не введёт ESC.
		Программа подсчитывает сумму всех введенных цифер.*/


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
	//так и не понял почему не хочет видеть первую букву в " SSum of numbers = ".
	//получается что если не добавить S напишет " um of numbers = "
}