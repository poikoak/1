#include <iostream>
#include "Student.h"
#include "Group.h"
using namespace std;

void main()
{
	FILE* fp;
	fp = fopen("DZ.txt", "rb+");
	if (fp == nullptr) {
		fp = fopen("DZ.txt", "wb+");
		if (fp == nullptr) {
			printf("CANNOT OPEN THE FILE");
		}
	}

	Group group(5);

	group.Add(new Student("Alex", "Petrov", 19, 1, 3.5));
	group.Add(new Student("Ivan", "Demidoff", 19, 1, 3.7));
	group.Add(new Student("Vasya", "Demidoff", 19, 1, 3.7));
	group.Add(new Student("Lena", "Petrova", 19, 1, 3.7));
	group.Add(new Student("Anna", "Karenina", 19, 1, 3.7));
	group.Print();
	/*group.SAVE();*/

	Group gr(5);
	gr.Add(new Student("Alex", "Petrov", 19, 2, 3.5));
	gr.Add(new Student("Ivan", "Demidoff", 19, 2, 3.7));
	gr.Print();
	group == gr;
	group >= gr;
	/*Group gr(5);
    gr = group;
	gr.Print();*/


	
}

