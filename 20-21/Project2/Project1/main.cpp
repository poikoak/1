#include "String.h"
#include "Exception.h"
#include <iostream>
using namespace std;


/*1. Для класса Strings добавить следующие методы:
-статическое поле count для подсчёта количества переменных типа Strings
- при работе со строками выбрасывать переменную класса StringsException для обработки
исключений(выход за границы, работа с файлами)
- операторы new, delete, new[], delete[], +=, -= (полное удаление строки из массива)
- Save
- Load*/

void Foo(const char* str)
{
	if(str=="1")
	{
		throw new Exception(1, "Division by zero!");
	}
	
}




int main() {

	
		String lines(2);
		lines.Add("...................................................");
		lines.Add("2");
		lines.Add("Three");
		lines.Add("Four");
		lines.Add("Five");
		lines.Add("Six");
		lines.Add("Seven");
		lines.Add("Eight");
		lines.Add("Nine");
		lines.Print();
		cout << "count = " << String::GetCount() << endl;





		try
		{
			Foo("1");
	    }
	catch (Exception* ex)
	{
		ex->Print();
		delete ex;
	}
	catch (...)
	{
		cout << "Unknown error!!!" << endl;
	}









}








