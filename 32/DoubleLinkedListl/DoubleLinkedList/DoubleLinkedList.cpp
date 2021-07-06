#include "DoubleLinkedList.h"
#include <iostream>
#include <fstream>
using namespace std;

DoubleLinkedList::DoubleLinkedList()
{
	head = tail = nullptr;
	count = 0;
}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& second)
{
	head = tail  = nullptr;
	count = 0;
	Element* current = second.head;
	while (current != nullptr)
	{		
		Add(current->str);		
		current = current->next;
	}
}

DoubleLinkedList::~DoubleLinkedList()
{
	Element* current = head;
	while (current != nullptr)
	{
		Element* temp = current;
		// "перепрыгнуть" на следующий элемент списка
		current = current->next;
		delete temp;
	}
}

void DoubleLinkedList::Add(string str)
{	
	if (head == nullptr)
	{
		head = tail = new Element(str, 0,0);
	}
	else 
	{
	
		Element* elem = new Element(str, 0,0);	
		tail->next = elem;	
		elem->prev = tail;
		tail = elem;
		
	}	
	count++;
}



void DoubleLinkedList::Print()
{
	Element* current = head;
	while (current != nullptr)
	{		
		cout << current->str << "->";		
		current = current->next;
	}
	cout << endl;
}







// префиксный инкремент
DoubleLinkedList& DoubleLinkedList::operator++()
{

	Element* current = head;
	//cout << "Prefix inc op" << endl;
	/*for (size_t i = 0; i < temp->str[i]; i++)
	{
		if (temp->str[i])
		{

			temp->str[i] = '!';
			i++;
		}
	}*/


	

	while (current != nullptr)
	{
		current->str = current->str + "!";
		current = current->next;
	}

	return *this;

}
DoubleLinkedList& DoubleLinkedList::operator--()
{
	Element* current = head;

	while (current != nullptr)
	{
		current->str.erase(0, 1);
		current = current->next;
	}

	return *this;
}
// постфиксный инкремент
DoubleLinkedList DoubleLinkedList::operator++(int)
{
	DoubleLinkedList result = *this;
	Element* current = head;

	while (current != nullptr)
	{
		/*char* temp = new char[strlen(current->str) + 1];
		strcpy(temp, current->str);
		delete[]current->str;
		current->str= new char[strlen(temp) + 2];
		strcpy(current->str, temp);
		strcat(current->str, "!");
		current = current->next;*/

		current->str = '!' + current->str;
		current = current->next;

	}
	//current = current->next;


	return result;
}
DoubleLinkedList DoubleLinkedList::operator--(int n)
{
	Element* current = head;
	while (current != nullptr)
	{	
		current->str.erase(current->str.length() - 1, current->str.length());
		current = current->next;
	}

	return *this;
}

void DoubleLinkedList::Save(const char* filename)
{
	fstream save(filename, ios::out);		
		Element* current = head;
		while (current != nullptr)
		{			
			save << current->str << "\n";		
			current = current->next;
		}
		save.close();		
		delete current;
	
}

void DoubleLinkedList::Load(const char* filename)
{
	fstream load(filename, ios::in);	
	{
		char* temp = new char[500];
		while (!load.eof())
		{
			load >> temp;
			Add(temp);
		}

		delete[] temp;
	}
}

ostream& operator<<(ostream& os, const DoubleLinkedList& second)
{
	Element* current = second.head;
	while (current != nullptr)
	{
		os << current->str << "\n";
		current = current->next;
	}

	return os;
}

istream& operator>>(istream& is, DoubleLinkedList& second)
{
	Element* current = second.head;
	while (current != nullptr)
	{
		is >> current->str;
		current = current->next;
	}

	return is;
}