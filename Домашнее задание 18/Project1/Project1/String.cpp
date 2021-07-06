#include "String.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void String::operator() (char ch1, char ch2)
{
	
	for (int i = 0; str[i] != 0; i++)
	{		
		if (str[i] == ch2) str[i] = ch1;
		else
		{
			if (str[i] == ch1)str[i] = ch2;
		}

	}

}

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


void String::Reverse()
{
	int len = strlen(str);

	for (int i = 0; i < len / 2; i++)
	{
		char t = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = t;
	}
}

void String::Save(char filename[])
{	
	FILE* file = fopen(filename, "w");
	if (file)
	{
		
		bool result = fputs(str, file); 
		if (!result) 
			cout << "Words are save in fail!" << endl; 
	}
	else
		cout << "no such file!" << endl;
	fclose(file);
}
void String::Load(char filename[])
{
	string line;
	ifstream in(filename); 
	if (in.is_open())
	{
		while (getline(in, line))
		{
			cout << line <<endl;
		}
	}
	in.close(); 
}