#include "Manager.h"
#include "Exeption.h"
#include <iostream>

using namespace std;

Manager::Manager(const char* FirstName, const char* LastName, unsigned int Age, int salary, int prize) : Employ(FirstName, LastName, Age)
{
	this->salary = salary; 
	this->prize = prize;
}

void Manager::Print()
{
	cout << "_____________________________" << endl;
	cout << "Manager : " << endl;
	// вызов метода базового класса
	Employ::Print();
	cout << "Salary : " << salary << endl;
	cout << "Prize  : " << prize << endl;
	cout << "_____________________________" << endl;
}

double Manager::GetPayment()
{
	return salary+=prize;
}
void Manager::SAVE()
{
	Employ::SAVE();
	FILE* File = fopen("SAVE.txt", "a");
	try
	{
		if (File != nullptr)
		{
			
				fprintf(File, "Prize  : %d\n", salary);
				fprintf(File, "Salary : %d\n", prize);
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