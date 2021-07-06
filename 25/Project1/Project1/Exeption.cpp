#include "Exeption.h"
#include <iostream>

using namespace std;

Exeption::Exeption(const int errorCode, const char* message)
{
	this->errorCode = errorCode;
	if (strlen(message) < 100)
		strcpy(this->message, message);

}


void Exeption::Print()
{
	cout << "ERROR: " << message << ", code: " << errorCode << endl;

}