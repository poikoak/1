#pragma once
#include "Employ.h"
class Freelancer : public Employ
{
	int TM;//Time and Material (T&M)
	int salary;

	
public:
	Freelancer(const char* FirstName, const char* LastName, unsigned int Age, int TM);
	void Print();
	double GetPayment();
	void SAVE();
};

