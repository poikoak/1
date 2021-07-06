#include "plane.h"
#include <iostream>
using namespace std;



int main()
{
	plane dots(5);
	dots.Add("...................................................");
	dots.Add("...................................................");
	dots.Add("...................................................");
	dots.Add("...................................................");
	dots.Add("...................................................");
	dots.print();
	plane dots2(5);
	dots2 = dots;
	cout << endl;
	dots2.print();
}