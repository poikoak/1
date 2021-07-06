#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList lst;
	lst.Add("One");
	lst.Add("Two");
	lst.Add("Three");
	lst.Add("One");
	lst.Print();

	char w[] = "KEKkkk";
	lst.Insert(w, 2);
	lst.Print();

	/*cout << endl;
	lst.Delete(1);	
	lst.Print();

	cout << endl;
	
	char q[] = "Three";
	lst.DeleteAll(q);
	cout << endl;
	lst.Print();

	LinkedList dst;
	dst.Add("123");
	dst.Add("321");
	lst + dst;
	lst.Print();*/

}
