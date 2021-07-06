#include "Freelancer.h"
#include "Exeption.h"
#include <iostream>
using namespace std;

Freelancer::Freelancer(const char* FirstName, const char* LastName, unsigned int Age, int TM) : Employ(FirstName, LastName, Age)
{
	this->TM = TM;
	salary = TM * 3;
}

void Freelancer::Print()
{
	cout << "_____________________________" << endl;
	cout << "Freelancer" << endl;
	// вызов метода базового класса
	Employ::Print();
	cout << "Rate 3 $ per hour"<< endl;
	cout << "Time at work : " << TM << endl;
	cout << "Salary : " << salary << endl;
	cout << "_____________________________" << endl;
}

double Freelancer::GetPayment()
{
	return salary;
}
void Freelancer::SAVE() 
{
	Employ::SAVE();
	FILE* File = fopen("SAVE.txt", "a");
	try
	{
		if (File != nullptr)
		{
			
				fprintf(File, "Time at work : %d\n", TM);
				fprintf(File, "Salary : %d\n", salary);
				fprintf(File, "_________________________\n");
			
			fclose(File);
		}
		else throw Exeption(777, "Wrong file name!");
	}
	catch (Exeption* exeption)
	{
		exeption->Print();
	}

}