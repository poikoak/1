#pragma once
#include "Employ.h"
class Manager : public Employ
{
	int salary;//оклад
	int prize;//премия
public:
	Manager(const char* FirstName, const char* LastName, unsigned int Age, int salary, int prize);
	void Print();
	double GetPayment();
	void SAVE();


};

