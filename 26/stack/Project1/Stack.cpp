#include "Stack.h"
#include <iostream>
#include "Exeption.h"
using namespace std;




Stack::Stack(size_t lines)
{
	     countstroke = 0;
		 capacity = lines;
	     arr = new int[capacity];
		 top = -1;
		
}
Stack::~Stack()
{
	delete[] arr;

	cout << "Destr" << endl;
}
void Stack::Push(int x)
{
	    if(countstroke < capacity)
	    {
	     arr[++top] = x;
		 countstroke++;
		}
		else throw  "Stack overflow";
	
}

int Stack::Pop()
{
	cout << "Removing " << arr[top] << endl;	
	return arr[top--];

}
int Stack::Clear()
{
	
	return top = -1;
}
int Stack::Lenght()
{
	return top + 1;
}
int Stack::Peek()
{	
	return arr[top];
}


