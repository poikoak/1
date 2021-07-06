#pragma once
#include <iostream>
#include <fstream>
using namespace std;

struct Element
{
	string str;
	Element* next;
	Element* prev;
	

	Element(string str, Element* next, Element* prev)
	{
		this->str = str;
		this->next = next;
		this->prev = prev;
		
	}

	~Element()
	{
		
	}
};



class DoubleLinkedList
{


	Element* head = nullptr; /* указатель на начало списка    */
	Element* tail = nullptr;   /* указатель последнего элем   */

	size_t count;

public:

	DoubleLinkedList() ;
	DoubleLinkedList(const DoubleLinkedList& second);
	~DoubleLinkedList();
	void Save(const char* filename);
	void Load(const char* filename);
	void Add(string str);
	void Print();// просмотр списка 

	// Префиксные инкременты
	DoubleLinkedList& operator++();
	DoubleLinkedList& operator--();

	// Постфиксные инкременты
	DoubleLinkedList operator++(int n);
	DoubleLinkedList operator--(int n);

	// Дружественные функции класса
	friend std::ostream& operator << (std::ostream& os, const DoubleLinkedList& second);
	friend std::istream& operator >> (std::istream& is, DoubleLinkedList& second);
};

