#pragma once
class Student
{

protected:

	
	char* FirstName;
	char* LastName;		
	unsigned int Age;
	unsigned int NumberGroup;
	double AvgMark;		

public:
	Student();
	Student(const Student& student);
	Student(const char* FirstName, const char* LastName, unsigned int Age, unsigned int  NumberGroup,double AvgMark);
	Student& operator= (Student& st);
	//Student& operator[] (int index);
	void Print();
	~Student();
	
};

