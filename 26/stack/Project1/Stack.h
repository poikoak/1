#pragma once
#include "Exeption.h"
class Stack
{
	
	int* arr;
	int top;
	int capacity;


	size_t lines;	
	size_t countstroke;



public:


	Stack(size_t lines);
	~Stack();
	void Push(int x);
	int Pop();
	int Clear();
	int Lenght();
	int Peek();
	bool isEmpty();
};

