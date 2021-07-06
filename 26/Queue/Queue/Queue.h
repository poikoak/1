#pragma once
class Queue
{
	int* arr;

	int capacity;
	

	size_t line;
	size_t countstroke;
public:
	Queue(size_t line);
	~Queue();
	void Enqueue(int x);
	int Dequeue();
	int Clear();
	int Lenght();
	int Peek();
};

