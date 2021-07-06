#include "Employ.h"
#include "Exeption.h"
#include <iostream>
using namespace std;

Employ::Employ(const char* FirstName, const char* LastName, unsigned int Age)
{
    this->FirstName = new char[strlen(FirstName) + 1];
    this->LastName = new char[strlen(LastName) + 1];
    strcpy(this->FirstName, FirstName);
    strcpy(this->LastName, LastName);
    this->Age = Age;
}

Employ::~Employ() 
{

    delete[] FirstName;
    delete[] LastName;

}


void Employ::Print()
{
  
    cout << FirstName << " " << LastName << endl;
    cout << "Age : " << Age << endl;
   

}

double Employ::GetPayment()
{
	return 0;
}



void Employ::SAVE()
{
	FILE* File= fopen("SAVE.txt", "a");
	try
	{
		if (File != nullptr)
		{
			
		     
				fprintf(File, "FirstName : %s\n", FirstName);
				fprintf(File, "LastName : %s\n", LastName);
				fprintf(File, "Age : %d\n", Age);
			
			fclose(File);
		}
		else throw Exeption(777, "Wrong file name!");
	}
	catch (Exeption* exeption)
	{
		exeption->Print();
	}


}