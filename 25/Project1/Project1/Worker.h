#pragma once
#include "Employ.h"
class Worker : public Employ
{
	int salary;//оклад
public:
	Worker(const char* FirstName, const char* LastName, unsigned int Age, int salary);
	void Print();
	double GetPayment();
	void SAVE();



};

