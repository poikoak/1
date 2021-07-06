#pragma once
class Exception
{

	int errorCode;
	char message[100];
public:
	Exception(const int code, const char* message);
	void Print();

};

