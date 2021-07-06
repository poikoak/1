#pragma once
#pragma warning(disable : 4996)
#include <string.h>
#include <fstream>


struct Element
{
	std::string str;
	Element* prev;
	Element* next;

	Element(std::string str, Element* prev, Element* next)
	{
		this->str = str;
		this->prev = prev;
		this->next = next;
	}

	~Element()
	{
		
	}
};

class DoubleLinkedList
{
	Element* first;
	Element* last;

	size_t count;

public:
	DoubleLinkedList();
	DoubleLinkedList(const DoubleLinkedList& second);
	~DoubleLinkedList();

	void Add(std::string str);
	void Print();

	// ���������� � ������ ������
	void AddFirst(std::string str);
	// �������� ������ � �������� �������
	void PrintBack();


	//-Element * Find(char* str) - ������� ������ ��������� �������� ������ �� ��������
	Element* Find(std::string str);
	//- void Clear() - ������� ��� �������� ������
	void Clear();
	//- void Insert(char* str, int pos) - ��������� ������� ����� ��������� � ��������� ��������
	void Insert(std::string str, size_t pos);
	//- void Delete(int pos) - �������� �������� �� �������
	void Delete(size_t pos);
	//- void Delete_All(char* str) - �������� ���� ��������� ������ � ������
	size_t Delete_All(std::string str);

	// ������������ ���������� �������� ������ � ������
	size_t Get_Count(std::string str);

	DoubleLinkedList& operator= (DoubleLinkedList& second);
	std::string operator[] (int pos);

	//- operator == -��������� �������
	bool operator== (DoubleLinkedList& second);
	//- operator + -���������� �������� � ����� ������
	DoubleLinkedList& operator+ (Element& elem);
	//- operator + -���������� ������ � ����� ������
	DoubleLinkedList& operator+ (DoubleLinkedList& second);
	//- operator += -���������� ������ � ����� ������
	DoubleLinkedList& operator+= (DoubleLinkedList& second);

	// ���������� ����������
	DoubleLinkedList& operator++();
	DoubleLinkedList& operator--();

	// ����������� ����������
	DoubleLinkedList operator++(int n);
	DoubleLinkedList operator--(int n);
	
	// ������������� ������� ������
	friend std::ostream& operator << (std::ostream& os, const DoubleLinkedList& second);
	friend std::istream& operator >> (std::istream& is, DoubleLinkedList& second);



	void Save(const char* filename);
	void Load(const char* filename);
};


