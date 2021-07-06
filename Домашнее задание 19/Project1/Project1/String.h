#pragma once
class String
{
	char* str;
public:
	
	String();
	String(const char* s);
	String(const char* q);
	~String();
	
	void print();
	void operator() (const char* s, char ch2);
	bool operator == (String& s);
	bool operator != (String& s);
	bool operator >= (String& s);
	bool operator <= (String& s);
	String operator + (char ch2);
	String operator - (char ch2);

};

