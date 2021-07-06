#include "Student.h"
#include "Person.h"
#include <iostream>

using namespace std;


void Student::SetDay(int day)
{
	if (day > 0 && day < 31)
	{
		this->day = day;
	}
}
int Student::GetDay() {
	return day;
}

void Student::SetMonth(int month) {
	if (month > 0 && month < 12)
	{
		this->month = month;
	}
}
int Student::GetMonth() {
	return month;
}

void  Student::SetYear(int year) {
	if (year > 0 && year < 3000)
	{
		this->year = year;
	}
}
int Student::GetYear() {
	return year;
}

void Student::SetAge(int age) {
	if (age > 0 && age < 100)
	{
		this->age = age;
	}
}
int Student::GetAge() {
	return age;
}

void Student::Print() {

	Person::Print();
	cout << "______________" << endl;
	cout<<"Acceptance Day" << endl;
	cout << "Day: " << day << " Month: " << month << " Year: " << year << endl;	
	cout << "Age of student: " << age << endl;
	
}