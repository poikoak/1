#include "Student.h"
#include <iostream>
using namespace std;


Student::Student(const char* FirstName, const char* LastName, unsigned int Age, unsigned int  NumberGroup, double AvgMark){
    cout << "Student constr" << endl;
    this->FirstName = new char[strlen(FirstName) + 1];
    this->LastName = new char[strlen(LastName) + 1];
    strcpy(this->FirstName, FirstName);
    strcpy(this->LastName, LastName);
    this->Age = Age;
    this->NumberGroup = NumberGroup;
    this->AvgMark = AvgMark;
}

Student::Student(const Student& student){
  
    this->FirstName = new char[strlen(student.FirstName) + 1];
    this->LastName = new char[strlen(student.LastName) + 1];
    strcpy(this->FirstName, student.FirstName);
    strcpy(this->LastName, student.LastName);
    this->Age = Age;
    this->NumberGroup = NumberGroup;
    this->AvgMark = AvgMark;
}

Student::~Student(){
    cout << "Person destr" << endl;
    delete[] FirstName;
    delete[] LastName;   
   
}



void Student::Print(){
   
    cout << endl;
    cout << FirstName << " " << LastName << endl;
    cout << "Age : " << Age << endl;
    cout << "Number of group : " << NumberGroup << endl;
    cout << "Avg Mark : " << AvgMark << endl;
    cout <<endl;
    cout << "_______________" << endl;
   
}



Student& Student::operator= (Student& student)
{
    cout << "Student operator =" << endl;
  
    if (FirstName != nullptr)
        delete[] FirstName;
    if (LastName != nullptr)
        delete[] LastName;

 
    FirstName = new char[strlen(student.FirstName) + 1];
    LastName = new char[strlen(student.LastName) + 1];

  
    strcpy(this->FirstName, student.FirstName);
    strcpy(this->LastName, student.LastName);

    return *this;
}


