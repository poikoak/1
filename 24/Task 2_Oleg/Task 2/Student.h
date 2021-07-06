#pragma once
#include "Person.h"

class Student :public Person
{
protected:
	char* faculty;
	char* specialty;
	int year;
	double av_grade;

public:
	Student();

	Student(const char* name, const char* fname, const int age,
		const char* gender, const char* faculty,
		const char* specialty, const int year, const double av_grade);

	~Student();

	void APrint();
	void APPrint();
	Student(const Student& source);

	Student& operator=( Student& source);

	
	void SetFac(char* temp);
	void SetSpec(char* temp);
	void SetYear(int temp);
	void SetAv_grade(double av_grade);

	char* GetFac();
	char* GetSpec();
	int GetYear();
	double GetAv_grade();

	

};

