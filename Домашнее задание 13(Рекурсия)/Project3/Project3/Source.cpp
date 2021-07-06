#include <iostream>
#include "conio.h"
#include <string> 
using namespace std;

//3. Рекурсивная функция принимает строку и букву и подсчитывает сколько раз буква встречается
//в строке.



int count_chars(const char* string, char s) 
{
	return *string ? count_chars(string + 1, s) + (s == *string) : 0;
}

int main()
{


	char string[] = "123qqwe345asd";
	char s = 'q';
	cout<< count_chars(string,s)<<endl;


	

}