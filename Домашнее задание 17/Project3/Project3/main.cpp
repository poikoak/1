#include "Vector.h"
#include <iostream>

void main()
{

	Vector vector;
	vector.Print();	
	vector.SetV(2,1);
	vector.GetV(2);
	vector.Print();

	/*vector.SetV(3, 2);
	vector.GetV(3);
	vector.Print();*/

	Vector vector1(1, 5);
	vector1.Print();

}