#pragma once

#include <iostream>

using namespace std;

struct Element
{
	char* str;
	Element* next;

	Element(const char* str, Element* next)
	{
		this->str = new char[strlen(str) + 1];
		strcpy(this->str, str);
		this->next = next;
	}

	~Element()
	{
		delete[] str;
	}
};

class LinkedList
{
	Element* first; /* указатель на начало списка    */
	Element* last;   /* указатель последнего элем   */
	Element* temp;   /* указатель текущего элемента   */
	size_t count;

public:
	LinkedList();
	LinkedList(const LinkedList& second);
	~LinkedList();
	void Add(const char* str);
	void Print();	
	// подсчитывает количество входений строки в список
	size_t GetCount(const char* str);
	LinkedList& operator= (LinkedList& second);
	char*& operator[] (int pos);


	Element* Find(char* str);
	void Clear();
	void Insert(char* str, int pos);
	
	void Delete(int pos);// -удаление элемента по позиции
	void DeleteAll(char* str);// -удаление всех вхождений строки в список
	bool operator == (LinkedList& second);//-сравнение списков
	bool operator+(LinkedList& second);
	bool operator+=(LinkedList& second);
	bool operator+(const char* str);
	//	operator + //-добавление элемента в конец списка
	//   operator + //-добавление списка в конец списка
	// operator += //-добавление списка в конец списка


};

