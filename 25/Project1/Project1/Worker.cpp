#include "Worker.h"
#include "Exeption.h"
#include <iostream>

using namespace std;

Worker::Worker(const char* FirstName, const char* LastName, unsigned int Age, int salary) : Employ(FirstName, LastName, Age)
{
	this->salary = salary;
}

void Worker::Print()
{	
	cout << "_____________________________" << endl;
	cout << "Worker:" << endl;
	// вызов метода базового класса
	Employ::Print();
	cout << "Salary : " << salary << endl << endl;
	cout << "_____________________________" << endl;
}

double Worker::GetPayment()
{
	return salary;
}
void Worker::SAVE()
{	
	
	FILE* File = fopen("SAVE.txt", "a");
	try
	{
		if (File != nullptr)
		{
			Employ::SAVE();
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