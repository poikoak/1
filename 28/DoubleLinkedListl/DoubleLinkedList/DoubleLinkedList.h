#pragma once
#include <iostream>
#include <fstream>
using namespace std;

struct Element
{
	char* str;
	Element* next;
	Element* prev;
	

	Element(const char* str, Element* next, Element* prev)
	{
		this->str = new char[strlen(str) + 1];
		strcpy(this->str, str);
		this->next = next;
		this->prev = prev;
		
	}

	~Element()
	{
		delete[] str;
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

	void Add(const char* str);
	void AddFirst(const char* str);/* - ���������� � ������ ������*/

	Element* Find(const char* str); //-������� ������ ��������� �������� ������ �� ��������
	void Insert(char* str, int pos);// -��������� ������� ����� ��������� � ��������� ��������
	void Clear();//������� ��� �������� ������

	void Print();// �������� ������ 
	void PrintBack();// �������� ������ � �������� �������	
	
	void Delete(int pos);// -�������� �������� �� �������
	size_t DeleteAll(char* str);// -�������� ���� ��������� ������ � ������


	void Save(const char* filename); //-���������� ������ � ����(fstream) - �������!
	void Load(const char* filename); // -�������� ������ �� �����(fstream)


	bool operator == (DoubleLinkedList& second);//-��������� �������
	bool operator+(DoubleLinkedList& second);//-���������� ������ � ����� ������
	bool operator+=(DoubleLinkedList& second);//-���������� ������ � ����� ������
	bool operator+(const char* str);//-���������� �������� � ����� ������
	
};

