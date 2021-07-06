#pragma once
class Ex
{
	int errorCode;
	char message[100];

public:
	Ex(const int errorcode, const char* message);

	void Print();
};
