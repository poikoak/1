#pragma once
class Exeption
{
	int errorCode;
	char message[100];

public:
	Exeption(const int errorcode, const char* message);

	void Print();
};

