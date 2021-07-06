#pragma once
class String
{
	char* str;
public:
	
	String();
	String(const char* s);
	~String();
	void print();
	void operator() (char ch1, char ch2);
	void Reverse();
	void Save(char filename[]);
	void Load(char filename[]);
};

