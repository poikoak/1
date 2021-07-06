#include "Header.h"
#include <iostream>

using namespace std;
//1. –азработать класс Person, который содержит следующие члены класса :
//-минимум 5 полей
//- конструктор без параметров
//- конструктор с параметрами
//- print() - печать на экран
//- сеттеры / геттеры дл€ доступа к пол€м

Person::Person(const char f_name[20], const char s_name[20], const char profession[20], int age, int year)
{
	if (strlen(f_name) > 0 && strlen(s_name) > 0 && strlen(profession) >0 && age > 17 && age < 61&& year > 1949 && year < 2021)
	{
		strcpy(this->f_name, f_name);
		strcpy(this->s_name, s_name);
		strcpy(this->profession, profession);
		this->age = age;
		this->year = year;
	}
	else
	{
		cout << "Error, invalid data" << endl;
	}

}

void Person::SetAge(int age)
{
	if (age > 17 && age < 61)
	{
		this->age = age;

	}
	

}
int Person::GetAge()
{
	return age;
}


	void Person::SetYear( int year)
	{
	if (year > 1949 && year < 2021)
	{
		
		this->year = year;
	}
	
	
}

	int Person::GetYear()
	{
		return year;
	}



void Person::Print()
{

	cout << "Firstname: " << f_name << endl;
	cout << "Surname: " << s_name << endl;
	cout << "Age: " << age << endl;
	cout << "Specialty: " << profession << endl;
	cout << "Date of obtaining the specialty: " << year << endl;
}


void main(int a,  char* q[])
{
	cout << "Program data " << endl;
	int age, year;
	cout << "Enter age 18-60: " << endl;
	cin >> age;
	cout << "Enter Date of obtaining the specialty 1950-2020: " << endl;
	cin >> year;
	Person Person("CHAMBA","MAMBA","tea master",age,year);
	Person.SetAge(age);
	Person.SetYear( year);
	Person.Print();
}