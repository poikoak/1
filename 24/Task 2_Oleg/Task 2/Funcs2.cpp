#include <iostream>
#include "Student.h"
#include "Ex.h"

using namespace std;

Student::Student():Person()
{
	
	this->faculty = new char[strlen("Unknown")+1];
	this->specialty = new char[strlen("Unknown") + 1];
	

	strcpy(this->faculty, "Unknown");
	strcpy(this->specialty, "Unknown");
	this->year = 0;
	this->av_grade = 0;
}

Student::Student(const char* name, const char* fname, const int age,
	const char* gender, const char* faculty, const char* specialty,
	const int year, const double av_grade):Person(name, fname, age, gender)
{

	
			this->faculty = new char[strlen(faculty)+1];
			this->specialty = new char[strlen(specialty)+1]; 
			
			strcpy(this->faculty, faculty);
			this->year = year;
			strcpy(this->specialty, specialty);
			this->av_grade = av_grade;
		
}

Student::~Student()
{
	delete[] faculty;
	delete[] specialty;
}

void Student::APrint()
{
	cout<<"\n"<<name<<" "<<fname;
	cout << "\n  ACADEMIC INFORMATION:";
	cout << "\n    *FacultyName: " << faculty;
	cout << "\n    *Specialty: " << specialty;
	cout << "\n    *Year: " << year;
	cout << "\n    *Average grade: " << av_grade;
}

void Student::APPrint()
{
	Person::PPrint();
	cout << "\n  ACADEMIC INFORMATION:";
	cout << "\n    *FacultyName: " << faculty;
	cout << "\n    *Specialty: " << specialty;
	cout << "\n    *Year: " << year;
	cout << "\n    *Average grade: " << av_grade;
}


void Student::SetFac(char* temp)
{
	try {
		if (strlen(faculty) == 0)
		{
			throw Ex(1, "The value not entered or entered incorrectly!");
		}
		else
		{
			strcpy(this->faculty, temp);
		}
	}
	catch (Ex& e)
	{
		e.Print();
		return;
	}

	return;
}

void Student::SetSpec(char* temp)
{
	try {
		if (strlen(specialty) == 0)
		{
			throw Ex(1, "The value not entered or entered incorrectly!");
		}
		else
		{
			strcpy(this->specialty, temp);
		}
	}
	catch (Ex& e)
	{
		e.Print();
		return;
	}

	return;
}

void Student::SetYear(int temp)
{
	try {
		if (year <= 0)
		{
			throw Ex(1, "The value not entered or entered incorrectly!");
		}
		else
		{
			this->year = temp;
		}
	}
	catch (Ex& e)
	{
		e.Print();
		return;
	}

	return;

}
void Student::SetAv_grade(double av_grade)
{
	try {
		if (av_grade< 0 || av_grade>100)
		{
			throw Ex(1, "The value entered incorrectly!");
		}
		else
		{
			this->av_grade = av_grade;
		}
	}
	catch (Ex& e)
	{
		e.Print();
		return;
	}

	return;
}



char* Student::GetFac()
{
	return faculty;
}


char* Student::GetSpec()
{
	return specialty;
}



int Student::GetYear()
{
	return year;
}
double Student::GetAv_grade()
{
	return av_grade;
}

Student::Student(const Student& source):Person(source)
{
	this->faculty = new char[strlen(source.faculty) + 1];
	this->specialty = new char[strlen(source.specialty) + 1];
	

	strcpy(this->faculty, source.faculty);
	this->year = source.year;
	strcpy(this->specialty, source.specialty);
	this->av_grade = source.av_grade;
	
}

Student& Student::operator=(Student& source)
{
	if (faculty != nullptr)
		delete[] faculty;
	if (specialty != nullptr)
		delete[] specialty;
	if (name != nullptr)
		delete[] name;
	if (fname != nullptr)
		delete[] fname;
	if (gender != nullptr)
		delete[] gender;
		
	faculty = new char[strlen(source.faculty) + 1];
	specialty = new char[strlen(source.specialty) + 1];
	name = new char[strlen(source.name) + 1];
	fname = new char[strlen(source.fname) + 1];
	gender = new char[strlen(source.gender) + 1];

	strcpy(this->faculty, source.faculty);
	this->year = source.year;
	strcpy(this->specialty, source.specialty);
	this->av_grade = source.av_grade;
	strcpy(this->name, source.name);
	strcpy(this->fname, source.fname);
	strcpy(this->gender, source.gender);
	this->age = source.age;

	return *this;
}
/*
char* Student::GetFac()
{
	char temp[80];
	strcpy(temp, this->faculty);
	return temp;
}


char* Student::GetSpec()
{
	char temp[80];
	strcpy(temp, this->specialty);
	return temp;
}*/