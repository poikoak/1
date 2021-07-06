#include "Ex.h"
#include <iostream>

using namespace std;

Ex::Ex(const int errorCode, const char* message)
{
	this->errorCode = errorCode;
	if (strlen(message) < 100)
		strcpy(this->message, message);

}


void Ex::Print()
{
	cout << "ERROR: " << message << ", code: " << errorCode << endl;

}