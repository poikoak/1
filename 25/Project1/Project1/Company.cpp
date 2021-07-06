#include "Company.h"
#include "Exeption.h"
#include <iostream>
using namespace std;

Company::Company(int maxSize)
{
	this->maxSize = maxSize;
	size = 0;
	employs = new Employ * [maxSize];
}

Company::~Company()
{
	for (size_t i = 0; i < size; i++)
	{
		delete employs[i];
	}

	delete[] employs;
}

void Company::Add(Employ* employ)
{
	if (size < maxSize)
		employs[size++] = employ;
}

void Company::Print()
{
	for (size_t i = 0; i < size; i++)
	{
		
		employs[i]->Print();
	}
}

double Company::GetPayment()
{
	float payment = 0;

	for (size_t i = 0; i < size; i++)
	{
		
		payment += employs[i]->GetPayment();
	}

	return payment;
}

void Company::SAVE()
{
	FILE* File = fopen("SAVE.txt", "w");
			for (size_t i = 0; i < size; i++)
			{
				
				employs[i]->SAVE();
				
			}
		
			
			fclose(File);
}

