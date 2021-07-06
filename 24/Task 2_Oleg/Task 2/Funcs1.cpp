#include <iostream>
#include "Person.h"
#include "Ex.h"

using namespace std;

Person::Person()
{
	this->name = new char[strlen("Unknown") + 1];
	this->fname = new char[strlen("Unknown") + 1];
	this->gender = new char[strlen("Unknown") + 1];
	
	strcpy(this->name, "Unknown");
	strcpy(this->fname, "Unknown"); 
	this->age = 0;
	strcpy(this->gender, "Unknown");
	
}

Person::Person(const char* name, const char* fname, const int age, const char* gender)
{
	
	this->name = new char[strlen(name)+1];
			this->fname = new char[strlen(fname)+1];
			this->gender = new char[strlen(gender)+1]; 
			
			strcpy(this->name, name);
			strcpy(this->fname, fname);
			this->age = age;
			strcpy(this->gender, gender);
			return;
}
void Person::PPrint()
{
	cout << "\n" << name << " " << fname;
	cout << "\n   PERSONAL INFORMATION:";
	cout << "\n    *Age: " << age;
	cout << "\n    *Gender: " << gender;
}
Person::~Person()
{
	delete[] name;
	delete[] fname;
	delete[] gender;
}

Person::Person(const Person& person)
{
	this->name = new char[strlen(person.name) + 1];
	this->fname = new char[strlen(person.fname) + 1];
	this->gender = new char[strlen(person.gender) + 1];

	strcpy(this->name, person.name);
	strcpy(this->fname, person.fname);
	this->age = person.age;
	strcpy(this->gender, person.gender);
	
}

/*Person& Person::operator=(const Person& person)
{
	cout << "Person = operator\n";
	if (name != nullptr)
		delete[] name;
	if (fname != nullptr)
		delete[] fname;
	if (gender != nullptr)
		delete[] gender;

	name = new char[strlen(person.name) + 1];
	fname = new char[strlen(person.fname) + 1];
	gender = new char[strlen(person.gender) + 1];

	strcpy(this->name, person.name);
	strcpy(this->fname, person.fname);
	strcpy(this->gender, person.gender);
	this->age = person.age;

	return *this;
}*/

void Person::SetAge(int age)
{
	try {
		if (age <= 0)
		{
			throw Ex(1, "The value not entered or entered incorrectly!");
		}
		else
		{
			this->age = age;
		}
	}
	catch (Ex& e)
	{
		e.Print();
		return;
	}

	return;
}

void Person::SetGender(char* gender)
{
	try {
		if (strlen(gender) == 0)
		{
			throw Ex(1, "The value not entered or entered incorrectly!");
		}
		else
		{
			strcpy(this->gender, gender);
		}
	}
	catch (Ex& e)
	{
		e.Print();
		return;
	}

	return;
}

void Person::SetName(char* name)
{
	try {
		if (strlen(name) == 0)
		{
			throw Ex(1, "The value not entered or entered incorrectly!");
		}
		else
		{
			strcpy(this->name, name);
		}
	}
	catch (Ex& e)
	{
		e.Print();
		return;
	}

	return;
}

void Person::SetFname(char* fname)
{
	try {
		if (strlen(fname) == 0)
		{
			throw Ex(1, "The value not entered or entered incorrectly!");
		}
		else
		{
			strcpy(this->fname, fname);
		}
	}
	catch (Ex& e)
	{
		e.Print();
		return;
	}

	return;
}


char* Person::getName()
{
	return name;

}

char* Person::getFname()
{
	return fname;

}

int Person::getAge()
{
	return age;
}

char* Person::getGender()
{
	return gender;

}


/*int Person::getAge()
{
	int temp = 0;
	temp = this->age;
	return temp;
}


char* Person::getName()
{
	char temp[80];
	strcpy(temp, this->name);
	return temp;

}

char* Person::getGender()
{
	char temp[80];
	strcpy(temp, this->gender);
	return temp;

}

char* Person::getFname()
{
	char temp[80];
	strcpy(temp, this->fname);
	return temp;
}

bool Person::findperson(const char* temp)
{
	return (strcmp(this->fname, temp) == 0) ? true : false;
}*/

