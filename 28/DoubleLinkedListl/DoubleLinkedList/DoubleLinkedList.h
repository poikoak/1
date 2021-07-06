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


	Element* head = nullptr; /* указатель на начало списка    */
	Element* tail = nullptr;   /* указатель последнего элем   */

	size_t count;

public:

	DoubleLinkedList() ;
	DoubleLinkedList(const DoubleLinkedList& second);
	~DoubleLinkedList();

	void Add(const char* str);
	void AddFirst(const char* str);/* - добавление в начало списке*/

	Element* Find(const char* str); //-находит первое вхождение элемента списка по значению
	void Insert(char* str, int pos);// -вставляет элемент перед элементом с указанной позицией
	void Clear();//очищает все элементы списка

	void Print();// просмотр списка 
	void PrintBack();// просмотр списка в обратном порядке	
	
	void Delete(int pos);// -удаление элемента по позиции
	size_t DeleteAll(char* str);// -удаление всех вхождений строки в список


	void Save(const char* filename); //-сохранение списка в файл(fstream) - сюрприз!
	void Load(const char* filename); // -загрузка списка из файла(fstream)


	bool operator == (DoubleLinkedList& second);//-сравнение списков
	bool operator+(DoubleLinkedList& second);//-добавление списка в конец списка
	bool operator+=(DoubleLinkedList& second);//-добавление списка в конец списка
	bool operator+(const char* str);//-добавление элемента в конец списка
	
};

