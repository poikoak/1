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

	// Добавление в начало списка
	void AddFirst(std::string str);
	// Просмотр списка в обратном порядке
	void PrintBack();


	//-Element * Find(char* str) - находит первое вхождение элемента списка по значению
	Element* Find(std::string str);
	//- void Clear() - очищает все элементы списка
	void Clear();
	//- void Insert(char* str, int pos) - вставляет элемент перед элементом с указанной позицией
	void Insert(std::string str, size_t pos);
	//- void Delete(int pos) - удаление элемента по позиции
	void Delete(size_t pos);
	//- void Delete_All(char* str) - удаление всех вхождений строки в список
	size_t Delete_All(std::string str);

	// подсчитывает количество входений строки в список
	size_t Get_Count(std::string str);

	DoubleLinkedList& operator= (DoubleLinkedList& second);
	std::string operator[] (int pos);

	//- operator == -сравнение списков
	bool operator== (DoubleLinkedList& second);
	//- operator + -добавление элемента в конец списка
	DoubleLinkedList& operator+ (Element& elem);
	//- operator + -добавление списка в конец списка
	DoubleLinkedList& operator+ (DoubleLinkedList& second);
	//- operator += -добавление списка в конец списка
	DoubleLinkedList& operator+= (DoubleLinkedList& second);

	// Префиксные инкременты
	DoubleLinkedList& operator++();
	DoubleLinkedList& operator--();

	// Постфиксные инкременты
	DoubleLinkedList operator++(int n);
	DoubleLinkedList operator--(int n);
	
	// Дружественные функции класса
	friend std::ostream& operator << (std::ostream& os, const DoubleLinkedList& second);
	friend std::istream& operator >> (std::istream& is, DoubleLinkedList& second);



	void Save(const char* filename);
	void Load(const char* filename);
};


