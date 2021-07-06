#include "Student.h"
#include "Person.h"
#include <iostream>

using namespace std;



void main() {

	Student student;

	student.SetName("VAS");
	
	student.SetLastName("CLASS");
	
	student.SetCity( "DON" );
	
	student.SetWork("MHS");
	
	student.SetDay(16);
	
	student.SetMonth(10);
	
	student.SetYear(2020);
	
	student.SetAge(25);
	
	student.Print();
}

