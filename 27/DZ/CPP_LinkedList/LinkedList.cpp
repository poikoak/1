#include "LinkedList.h"
#include <iostream>
#include <cstdio>
using namespace std;

LinkedList::LinkedList()
{
	first = last = temp = nullptr;

	count = 0;
}

LinkedList::LinkedList(const LinkedList& second)
{
	first = last = temp = nullptr;

	count = 0;

	Element* current = second.first;

	while (current != nullptr)
	{
		// добавить текущий элемент копируемого списка в новый список
		Add(current->str);

		// "перепрыгнуть" на следующий элемент списка
		current = current->next;
	}
}

LinkedList::~LinkedList()
{
	Element* current = first;

	while (current != nullptr)
	{
		Element* temp = current;
		
		// "перепрыгнуть" на следующий элемент списка
		current = current->next;

		delete temp;
	}
}

void LinkedList::Add(const char* str)
{
	// список пуст?
	if (first == nullptr)
	{
		first = last = new Element(str, 0);
	}
	else // список не пуст
	{
		// создать новый элемент списка
		Element* elem = new Element(str, 0);

		// последний элемент списка указывает на новый созданный элемент
		last->next = elem;

		// поменять указатель на последний элемент
		last = elem;
	}

	// увеличить количество элементов на 1
	count++;
}

void LinkedList::Print()
{
	Element* current = first;

	while (current != nullptr)
	{
		// вывести на экран содержимое текущего элемента списка
		cout << current->str << endl;

		// "перепрыгнуть" на следующий элемент списка
		current = current->next;
	}

	cout << endl;
}

size_t LinkedList::GetCount(const char* str)
{
	size_t result = 0;
	Element* current = first;

	while (current != nullptr)
	{
		if (strcmp(current->str, str) == 0)
			result++;

		// "перепрыгнуть" на следующий элемент списка
		current = current->next;
	}

	return result;
}

LinkedList& LinkedList::operator= (LinkedList& second)
{
	// удаление старых элементов списка
	Element* current = first;

	while (current != nullptr)
	{
		Element* temp = current;

		// "перепрыгнуть" на следующий элемент списка
		current = current->next;

		delete temp;
	}

	first = last = nullptr;

	// добавление новых элементов
	current = second.first;

	while (current != nullptr)
	{
		Add(current->str);

		// "перепрыгнуть" на следующий элемент списка
		current = current->next;
	}

	return *this;
}

char*& LinkedList::operator[] (int pos)
{
	int n = 0;
	Element* current = first;

	while (current != nullptr)
	{
		if (pos == n)
			return current->str;

		// "перепрыгнуть" на следующий элемент списка
		current = current->next;

		n++;
	}

	throw exception("Incorrect index!!!");
}



///////////////////////////////////////////////////////////////
void LinkedList::Clear()
{
	Element* current = first;
	if (current == nullptr) return;
	do {
		Element* N = current;
		current->str;
		delete N;
	} while (current != nullptr);
	count = 0;
	first = nullptr;
}
void LinkedList::Insert(char* str, int pos)
{
	if (first == nullptr)
	{
		first=last= new Element(str, 0);
	}

	Element* current = first;
	Element* pre = new Element(str, 0);
	Element* temp = new Element(str, 0);
	
	
	for (int i = 0; i < pos; i++)
	{
		
		pre = current;
		current = current->next;
	}
	//temp->str = str;
	pre->next = temp;
	temp->next = current;
	count++;
}
void LinkedList::Delete(int pos)
{
	
	Element* current = first;
	Element* pre = temp;
	current = first;
	
		for (int i = 0; i < pos; i++)
		{
			 pre = current;
			 current = current->next;
		}
		

		pre->next = current->next;
		
	
	
	//throw exception("Incorrect index!!!");

	
}


void LinkedList::DeleteAll(char* str)
{
	////не пашет
	//Element* current = first;
	//Element* pre = first;
	////Element* pre = new Element(str, 0);
	//current = first;
	//
	//	for (int i = 0; i < count; i++)
	//	{
	//		if (strcmp(current->str, str) == 0)
	//		{

	//			pre = current;
	//			current = current->next;
	//		}
	//		pre->next = current->next;
	//		
	//	}
	//	
	//////////////////////////////////////////////////	
		/*Element* current = first;
		while (first->str == str)
		{
			first = first->next;
		}
				
			if (current->next->str == str)
			{
				current->next = current->next->next;
			}
			else
			{
				current = current->next;
			}*/
	//Element* current = first;
	/////////////////////////////////////////////////////
	//  // Store head node 
	//Element* current = first;
	//Element* pre = new Element(str, 0);
	//Element* head = new Element(str, 0);
	//// If head node itself holds the key or multiple occurrences of key 
	//while (current != nullptr && current->str == str)
	//{
	//	head = current->next;   // Changed head 
	//	free(current);               // free old head 
	//	current = head;         // Change Temp 
	//}
	//// Delete occurrences other than head 
	//
	//	// Search for the key to be deleted, keep track of the 
	//	// previous node as we need to change 'prev->next' 
	//	while (current != nullptr && current->str == str)
	//	{
	//		pre = current;
	//		current = current->next;
	//	}
	//	// If key was not present in linked list 
	//	if (current == nullptr) return;
	//	// Unlink the node from linked list 
	//	pre->next = current->next;
	//	free(current);  // Free memory 
	//	//Update Temp for next iteration of outer loop 
	//	current = pre->next;
	
	//////////////////////////////////////////////
	while (first != nullptr && first->str == str)
		first = first->next;

	/* Now, delete remaining occurrences of the key from the linked list by storing the previous
	node and pointing it to desired location accordingly */
	Element* current = first;
	
		if (current->next->str == str)
		{
			Element *p= current->next;
			current->next = current->next->next;
			delete p;
		}
		else
		{
			current = current->next;
		}
	
}

bool LinkedList::operator== (LinkedList& second)
{
	Element* current = first;
	Element* current_second = second.first;
	if (count != second.count)
		return false;
	else
	{
		while (current != nullptr)
		{
			if (strcmp(current->str, current_second->str) == 0)
				return false;
			current = current->next;
			current_second = current_second->next;
		}
		return true;
	}
	
}

//Element* LinkedList::Find(char* str)
//{
//	
//}

bool LinkedList::operator+(LinkedList& second)
{
	
	Element* current = this->first;
	if (first == nullptr) 
	{
		first = second.first;
	}
	else
	{
		while (current->next != nullptr)
		{
			current = current->next;
			
		}
		current->next = second.first;
		count++;
	}
	
	return true;
	
}

bool LinkedList::operator+=(LinkedList& second)
{

	Element* current = this->first;
	if (first == nullptr)
	{
		first = second.first;
	}
	else
	{
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = second.first;
	}
	count++;
	return true;

}
//bool LinkedList::operator+(const char* str)
//{
//
//	Element* current = this->first;
//	if (first == nullptr)
//	{
//		first = str.first;
//	}
//	else
//	{
//		while (current->next != nullptr)
//		{
//			current = current->next;
//		}
//		current->next = str.first;
//	}
//	count++;
//
//
//}