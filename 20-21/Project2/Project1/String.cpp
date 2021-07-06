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


// инициализация статического поля класса
int String::count = 0;
String::String()
{
	maxLinesCount = 10;
	reserveSize = 5;
	countstroke = 0;

	// создание массива указателей на строки
	str = new char* [maxLinesCount];
	
}

String::String(size_t lines)
{
	countstroke = 0;
	reserveSize = 5;
	maxLinesCount = lines;

	// создание массива указателей на строки
	str = new char* [maxLinesCount];
	this->str = str;
	
	
}


String::~String()
{
	// удаление заполненных строк
	for (size_t i = 0; i < count; i++)
	{
		delete[] str[i];
	}

	// удаление массива указателей
	delete[] str;
}



void String::Print()
{
	for (size_t i = 0; i < countstroke; i++)
	{
		cout << this->str[i] << endl;
	}
	cout << endl;
}








int String::GetCount()
{
	return count;
}







void String::StretchLines()
{
	cout << "StretchLines" << endl;
	// создание массива указателей на строки
	char** new_str = new char* [maxLinesCount + reserveSize];

	// копирование адресов существующих строк
	for (size_t i = 0; i < maxLinesCount; i++)
	{
		new_str[i] = str[i];
	}

	// удаление старого массива указателей
	delete[] str;

	// переместить адрес нового массива указателей в поле класса str
	str = new_str;

	// увеличить максимальное доступное количество строк
	maxLinesCount += reserveSize;
}










const char* Ex(const char* s)
{

	if (s == "1" && s == "2" && s == "3" && s == "4" && s == "5" && s == "6" && s == "7" && s == "8"
		&& s == "9")
	
		throw new Exception(666, "do not enter such numbers!");
	
	return s;
}





void String::Add(const char* s)
{


	// если не хватает места для хранения адресов строк в массиве указателей на строки
	// то увеличить массив указателей
	if (countstroke >= maxLinesCount)
		StretchLines();

	// выделение памяти для новой (последней) строки
	str[countstroke] = new char[strlen(s) + 1];

	// скопировать строку в массив строк
	strcpy(str[countstroke], s);

	// увеличить количество заполненных строк
	countstroke++;
	count++;
	FILE* file = fopen("file1.txt", "w");
	if (file != nullptr)
	{
		char buffer[100];
		strcpy(buffer, s);

		strcpy(buffer, " ");
		fputs(buffer, file);
		fclose(file);

	}
}
		
// оператор запускается при попытке создания объекта при помощи стандартного оператора new
void* String::operator new(size_t t)
{
	void* p = malloc(t);
	cout << "op new. Size: " << t << endl;
	return  p;
}

// оператор запускается при попытке удаления объекта при помощи стандартного оператора delete
void String::operator delete(void* p)
{
	cout << "op delete" << endl;
	free(p);
}

// оператор запускается при попытке создания объекта при помощи стандартного оператора new
void* String::operator new[](size_t t)
{
	void* p = malloc(t);
	cout << "op new[]. Size: " << t << endl;
	return  p;
}

// оператор запускается при попытке удаления объекта при помощи стандартного оператора delete
void String::operator delete[](void* p)
{
	cout << "op delete[]" << endl;
	free(p);
}

//String& String::operator+= (String& t)
//{
//	if (maxLinesCount != t.maxLinesCount)
//		return *this;
//
//	for (size_t i = 0; i < maxLinesCount; i++)
//	{
//		str[i] += t.str[i];
//	}
//	return *this;
//}
//
//String& String::operator-= (String& t)
//{
//	if (maxLinesCount != t.maxLinesCount)
//		return *this;
//
//	for (size_t i = 0; i < maxLinesCount; i++)
//	{
//		str[i] -= t.str[i];
//	}
//	return *this;
//}


void String::SAVE(const char* str)
{
	FILE* file = fopen("file1.txt", "w");
	if (file != nullptr)
	{
		char buffer[100];
		strcpy(buffer, str);
			
				strcpy(buffer, " ");
				fputs(buffer, file);
				fclose(file);

	}

}