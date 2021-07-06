#pragma once
#include "Employ.h"

class Company
{
	
	Employ** employs;
	int size;
	size_t maxSize;
public:
	Company(int maxSize);
	~Company();
	void Add(Employ* employ);
	void Print();
	double GetPayment();
	void SAVE();

};

