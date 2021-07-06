#include "Person.h"
#include <iostream>

using namespace std;

void Person::SetName(const char name[20])
{

	if (strlen(name) > 0 && strlen(name) < 20)
	{
		strcpy(this->name, name);
		
	}
	else
	{
		cout << "Error, invalid data" << endl;
	}
}
char* Person::GetName()
{

	return name;
}
void Person::SetLastName(const char lastname[20])
{
	if (strlen(lastname) > 0 && strlen(lastname) < 20)
	{
		strcpy(this->lastname, lastname);

	}
	else
	{
		cout << "Error, invalid data" << endl;
	}
}
char* Person::GetLastName()
{
	return lastname;
}
void Person::SetCity(const char city[20])
{
	if (strlen(city) > 0 && strlen(city) < 20)
	{
		strcpy(this->city, city);

	}
	else
	{
		cout << "Error, invalid data" << endl;
	}
}
char* Person::GetCity()
{
	return city;
}
void Person::SetWork(const char work[20])
{
	if (strlen(work) > 0 && strlen(work) < 20)
	{
		strcpy(this->work, work);

	}
	else
	{
		cout << "Error, invalid data" << endl;
	}
}
char* Person::GetWork()
{
	return work;
}



void Person::Print()
{

	cout << "Firstname: " << name << endl;
	cout << "Lastname: " << lastname << endl;
	cout << "City: " << city << endl;
	cout << "Work: " << work << endl;
	
}