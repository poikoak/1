#include "String.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



String::String(const char* s)
{
	str = new char[strlen(s) + 1];
	strcpy(str, s);
}


String::~String()
{
	delete[] str;
}



void String::print()
{
	cout << str << endl;
}

