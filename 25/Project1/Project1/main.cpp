#include <iostream>
#include "Company.h"
#include "Employ.h"
#include "Freelancer.h"
#include "Manager.h"
#include "SalesPerson.h"
#include "Worker.h"
using namespace std;



int main()
{
	Company* doc = new Company(20);
	doc->Add(new Manager("Vadik", "Aladik", 30, 2000, 800));
	doc->Add(new Worker("Gricha","Gulisha",22,1000));
	doc->Add(new Freelancer("Chamba", "Mamba",27, 100));
	doc->Add(new Manager("Vadik", "Aladik", 30,2000,800));
	doc->Add(new SalesPerson("Petr", "Osetr", 36,243));
	doc->Print();
	cout << endl;
	cout << endl;
	cout << "Total salary of all companies = " << doc->GetPayment() << endl;

	doc->SAVE();
	delete doc;
}