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

	cout << "Add first!!!" << endl;
	lst.AddFirst("Appollo");	
	lst.Print();

	cout << "printback!!!" << endl;
	lst.PrintBack();

	cout << "insert!!!" << endl;
	char w[] = "KEKkkk";
	lst.Insert(w, 2);
	lst.Print();

	cout << "delete element!!!" << endl;
	lst.Delete(1);
	lst.Print();	


	cout << "Delete ""Three""!!!" << endl;
	char q[] = "Three";
	lst.DeleteAll(q);
	cout << endl;
	lst.Print();

	

	cout << "Save & LOAD!!!" << endl;
	lst.Save("in.txt");
	lst.Load("in.txt");
	lst.Print();

	cout << "find element!!!" << endl;
	
	lst.Find("65");

	/*DoubleLinkedList dst;
	dst.Add("123");
	dst.Add("321");
	lst + dst;
	lst.Print();*/

}
