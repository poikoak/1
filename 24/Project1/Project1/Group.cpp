#include "Group.h"
#include <fstream>
#include <iostream>
using namespace std;


Group::Group(size_t max_size){
	cout << "Group constr" << endl;
	size = 0;
	MaxSize = max_size;	
	students = new Student * [MaxSize];
}

Group::~Group(){
	cout << "Group destr" << endl;
	for (size_t i = 0; i < size; i++)
	{
		delete students[i];
	}	
	delete[] students;
}

Group::Group(const Group& student) 
{
	//this->FirstName = new char[strlen(student.FirstName) + 1];
	//this->LastName = new char[strlen(student.LastName) + 1];
	//strcpy(this->FirstName, student.FirstName);
	//strcpy(this->LastName, student.LastName);
	//this->Age = Age;
	//this->NumberGroup = NumberGroup;
	//this->AvgMark = AvgMark;


	cout << "Copy student constr" << endl;
	this->MaxSize = student.MaxSize;
	students = new Student *[MaxSize];
	for (size_t i = 0; i < MaxSize; i++)
	{
		students[i] = student.students[i];
	}
}
//void Group::SAVE( )
//{
//	ofstream FILE("DZ.txt");
//		if (FILE)
//		{
//			FILE << size << "\n";
//				for (int i = 0; i < size; i++)
//				{
//					FILE << FirstName;
//					FILE << "\n";
//
//				}
//			FILE.close();
//		}
//		
//
//}
// проверка на наличие свободного места и пересоздание массива студентов, если это нужно
void Group::CheckSize(){	
	if (size >= MaxSize){
		cout << "CheckSize add memory" << endl;	
		Student** new_students = new Student * [MaxSize + NewStudentsAmount];		
		for (size_t i = 0; i < size; i++)
		{			
			new_students[i] = students[i];
		}	
		delete[] students;	
		students = new_students;	
		MaxSize = MaxSize + NewStudentsAmount;
	}
}

void Group::Add(Student* st){	
	CheckSize();	
	students[size] = st;	
	size++;

	//сохранение в фаил только ссылки
	ofstream FILE("DZ.txt");
	if (FILE)
	{
		FILE << st << "\n";
		for (int i = 0; i < size; i++)
		{
			FILE << students[i];
			FILE << "\n";

		}
		FILE.close();
	}
	

			
		
}

void Group::Print(){
	for (size_t i = 0; i < size; i++)
	{
		students[i]->Print();
	}
}



bool Group::operator == (Group& arr2)
{
	

	for (size_t i = 0; i < size; i++)
	{
		if (students[i] == arr2.students[i])
			return true;
	}

	return false;
}


bool Group::operator >= (Group& arr2)
{
	

	for (size_t i = 0; i < size; i++)
	{
		if (students[i] >= arr2.students[i])
			return true;
	}

	return false;
}

//const char& Group::operator[] (int index)
//{
//	if (index >= 0 && index < size)
//	{
//		return students[index];
//	}
//
//	return students[0];
//}

//Group& Group::operator= ( Group& s)
//{
//	cout << "Operator =" << endl;
//	if (MaxSize != s.MaxSize)
//	{
//		for (size_t i = 0; i < size; i++)
//		{
//			delete students[i];
//		}
//		delete[] students;
//		students = new Student * [s.MaxSize];
//		MaxSize = s.MaxSize;
//	}
//
//	// копирование одной области памяти в другую через указатели
//	memcpy(students, s.students, MaxSize * sizeof(int));
//	memcpy(students, s.students, MaxSize * sizeof(char));
//	for (size_t i = 0; i < size; i++)
//	{
//		// выделение памяти для новой (последней) строки
//		students[i] = new char[strlen(source.students[i]) + 1];
//
//		// скопировать строку из исходного объекта в новый объект
//		strcpy(students[i], so.students[i]);
//	}
//
//	return *this;
//}
//Group& Group::operator= (Student& student)
//{
//
//	PPP(Group & s);
//	CheckSize();
//	students[size] = s;
//	size++;
//
//
//
//	return *this;
//}
//
//void Group::PPP(Group& s) {
//	cout << "Operator =" << endl;
//	if (MaxSize != s.MaxSize)
//	{
//		for (size_t i = 0; i < size; i++)
//		{
//			delete students[i];
//		}
//		delete[] students;
//		students = new Student * [s.MaxSize];
//		MaxSize = s.MaxSize;
//	}
//}


//Group& Group::operator[] (int index)
//{
//	if (index >= 0 && index < size)
//	{
//		return students[index]->Print();
//	}
//
//	
//}
