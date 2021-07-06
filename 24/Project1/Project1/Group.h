#pragma once
#include "Student.h"
class Group 
{
private:	
	void CheckSize();
	
protected:

	
	Student** students;	
	size_t size;	
	size_t MaxSize;	
	const size_t NewStudentsAmount = 2;
public:
	Group();
	Group(size_t max_size);
	~Group();
	void Add(Student* st);
	void Print();
	Group(const Group& student);
	//Group& operator=(Student& student);
	//Group& operator = (Group& s);
	/*void SAVE();
	void LOAD();*/

	//Group operator + (Group& arr2);
	//Group& operator[] (int index);

	bool operator == (Group& arr2);
	bool operator >= (Group& arr2);
	/*const char& operator[] (int index);*/
};

