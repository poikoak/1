#include "DoubleLinkedList.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	DoubleLinkedList lst;
	lst.Add("One");
	lst.Add("Two");
	lst.Add("Three");
	lst.Add("65");
	lst.Print();

	
	
	++lst;
	lst.Print();
	lst++;
	lst.Print();
	ofstream res;
	res.open("result.txt");
	if (!res.fail())
	{
		res << lst;
		res.close();
	}
	
}
