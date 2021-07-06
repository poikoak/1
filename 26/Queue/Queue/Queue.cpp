#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(size_t line)
{
	countstroke = 0;
	capacity = line;
	arr = new int[capacity];
	
}

Queue::~Queue()
{
	delete[]arr;
}
void Queue::Enqueue(int x) 
{	
		arr[countstroke++] = x;
}
int Queue::Dequeue() 
{
	int first = arr[0];
	//сдвигаем все элементы
	for (int i = 1; i < countstroke; i++)
		arr[i - 1] = arr[i];
	countstroke--;//уменьшаем	
	return first;
}
int Queue::Clear() 
{
	return countstroke = 0;
}
int Queue::Lenght() 
{
	return countstroke;
}
int Queue::Peek() 
{
	return arr[0];
}
