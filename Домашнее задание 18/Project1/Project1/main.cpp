#include <iostream>
#include "String.h"

using namespace std;

void main()
{
	String str("Hello big world!!!");
	str.print();
	str.operator()('!', 'K');
	str.print();
	str.Reverse();
	str.print();
	char destFilename[200];
	cout << "Enter name of destination file: ";
	cin.getline(destFilename, 200);
	str.Save(destFilename);
	str.Load(destFilename);
}