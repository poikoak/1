#pragma once
#include "Student.h"

class Group:public Student
{
protected:

	int count;
	int maxcount;
	Student** sts;

public:

	Group();
	Group(int count);

	void Add(const char* name, const char* fname, const int age, const char* gender, const char* faculty, const char* specialty, const int year, const double av_grade);

	void Add(Student* st);

	~Group();

	Group(const Group& source);

	void Print();
	void PPrint();
	void APrint();

	Group& operator=(const Group& source);

	void operator+(Student* st);

	void operator+=(Student* st);

	Group& operator+=(const Group& source);

	bool operator==(const Group& source);

	bool operator>=(const Group& source);

	void operator() ();

	
	
	void Save(const char* filename);

	Group& Load(const char* filename);

	Student* operator[] (const char* name);

};

