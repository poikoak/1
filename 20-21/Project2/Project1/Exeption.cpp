#include "Exception.h"
#include <iostream>

using namespace std;

Exception::Exception(const int code, const char* message)
{
	errorCode = code;
	if (strlen(message) < 100)
		strcpy(this->message, message);
}

void Exception::Print()
{
	cout << "ERROR: " << message << ", Code : " << errorCode << endl;
}
