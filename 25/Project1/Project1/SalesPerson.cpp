#include "SalesPerson.h"
#include "Exeption.h"
#include <iostream>

using namespace std;

SalesPerson::SalesPerson(const char* FirstName, const char* LastName, unsigned int Age,int sold) : Employ(FirstName, LastName, Age)
{
	this->sold = sold;
	
	p = sold * Price;
	payment= p*3 / 100;
	
}

void SalesPerson::Print()
{
	cout << "_____________________________" << endl;
	cout << "SalesPerson " << endl;
	// вызов метода базового класса
	Employ::Print();
	cout << "Goods sold : " << sold << endl;
	cout << "Price per item : " << Price << endl;
	cout << "Total sales : " << p << endl;
	cout << "3 % of sales " << endl;
	cout << "Payment : " << payment << endl;
	cout << "_____________________________" << endl;
}

double SalesPerson::GetPayment()
{
	return payment;
}
void SalesPerson::SAVE()
{
	Employ::SAVE();
	FILE* File = fopen("SAVE.txt", "a");
	try
	{
		if (File != nullptr)
		{
			
				fprintf(File, "Goods sold : %d\n", sold);
				fprintf(File, "Price per item : %d\n", Price);
				fprintf(File, "Total sales : %d\n", p);
				fprintf(File, "Payment  : %d\n", payment);
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