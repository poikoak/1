#include "Vector.h"
#include <iostream>

using namespace std;
Vector::Vector()
{

	     index = 0;
		v[index] = 4;
}
void Vector::SetV(int index, int number)
{
	if (index >= 0 && index < 5)
	{
		this->index = index;
		v[index] = number;
	}
}
int Vector::GetV(int index)
{
	this->index = index;
	return v[index];
}

Vector::Vector(int index, int number)
{
	this->index = index;
	this->v[index] = number;


}
void Vector::Print()
{

	cout << "V[" << index << "] = " << v[index] << endl;


}
