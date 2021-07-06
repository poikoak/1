#include "String.h"
#include "Exception.h"
#include <iostream>
using namespace std;


/*1. ��� ������ Strings �������� ��������� ������:
-����������� ���� count ��� �������� ���������� ���������� ���� Strings
- ��� ������ �� �������� ����������� ���������� ������ StringsException ��� ���������
����������(����� �� �������, ������ � �������)
- ��������� new, delete, new[], delete[], +=, -= (������ �������� ������ �� �������)
- Save
- Load*/


// ������������� ������������ ���� ������
int String::count = 0;
String::String()
{
	maxLinesCount = 10;
	reserveSize = 5;
	countstroke = 0;

	// �������� ������� ���������� �� ������
	str = new char* [maxLinesCount];
	
}

String::String(size_t lines)
{
	countstroke = 0;
	reserveSize = 5;
	maxLinesCount = lines;

	// �������� ������� ���������� �� ������
	str = new char* [maxLinesCount];
	this->str = str;
	
	
}


String::~String()
{
	// �������� ����������� �����
	for (size_t i = 0; i < count; i++)
	{
		delete[] str[i];
	}

	// �������� ������� ����������
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
	// �������� ������� ���������� �� ������
	char** new_str = new char* [maxLinesCount + reserveSize];

	// ����������� ������� ������������ �����
	for (size_t i = 0; i < maxLinesCount; i++)
	{
		new_str[i] = str[i];
	}

	// �������� ������� ������� ����������
	delete[] str;

	// ����������� ����� ������ ������� ���������� � ���� ������ str
	str = new_str;

	// ��������� ������������ ��������� ���������� �����
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


	// ���� �� ������� ����� ��� �������� ������� ����� � ������� ���������� �� ������
	// �� ��������� ������ ����������
	if (countstroke >= maxLinesCount)
		StretchLines();

	// ��������� ������ ��� ����� (���������) ������
	str[countstroke] = new char[strlen(s) + 1];

	// ����������� ������ � ������ �����
	strcpy(str[countstroke], s);

	// ��������� ���������� ����������� �����
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
		
// �������� ����������� ��� ������� �������� ������� ��� ������ ������������ ��������� new
void* String::operator new(size_t t)
{
	void* p = malloc(t);
	cout << "op new. Size: " << t << endl;
	return  p;
}

// �������� ����������� ��� ������� �������� ������� ��� ������ ������������ ��������� delete
void String::operator delete(void* p)
{
	cout << "op delete" << endl;
	free(p);
}

// �������� ����������� ��� ������� �������� ������� ��� ������ ������������ ��������� new
void* String::operator new[](size_t t)
{
	void* p = malloc(t);
	cout << "op new[]. Size: " << t << endl;
	return  p;
}

// �������� ����������� ��� ������� �������� ������� ��� ������ ������������ ��������� delete
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