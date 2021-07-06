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


	Element* head = nullptr; /* ��������� �� ������ ������    */
	Element* tail = nullptr;   /* ��������� ���������� ����   */

	size_t count;

public:

	DoubleLinkedList() ;
	DoubleLinkedList(const DoubleLinkedList& second);
	~DoubleLinkedList();
	void Save(const char* filename);
	void Load(const char* filename);
	void Add(string str);
	void Print();// �������� ������ 

	// ���������� ����������
	DoubleLinkedList& operator++();
	DoubleLinkedList& operator--();

	// ����������� ����������
	DoubleLinkedList operator++(int n);
	DoubleLinkedList operator--(int n);

	// ������������� ������� ������
	friend std::ostream& operator << (std::ostream& os, const DoubleLinkedList& second);
	friend std::istream& operator >> (std::istream& is, DoubleLinkedList& second);
};

