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
		// "������������" �� ��������� ������� ������
		current = current->next;
		delete temp;
	}
}

void DoubleLinkedList::Add(const char* str)
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

void DoubleLinkedList::AddFirst(const char* str)
{
		Element* elem = new Element(str, 0,0);
		if (head == nullptr)
		{
			head = elem;
			tail = elem;
		}
		else
		{
			elem->next = head;
			head = elem;
			elem->next->prev = elem;		
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

void DoubleLinkedList::PrintBack()
{
	Element* temp = tail;	
	while (temp != nullptr)
	{
		cout << temp->str << "->";
		temp = temp->prev;
	}
	cout << endl;
}

///////////////////////////////////////////////////////////////
void DoubleLinkedList::Clear()
{
	Element* current = head;
	if (current == nullptr) return;
	do {
		Element* N = current;
		current->str;
		delete N;
	} while (current != nullptr);
	count = 0;
	head = nullptr;
	tail = nullptr;
}
void DoubleLinkedList::Insert(char* str, int pos)
{
	if (head == nullptr)
	{
		head = tail = new Element(str, 0,0);
	}

	Element* current = head;
	Element* pre = new Element(str, 0,0);
	Element* temp = new Element(str, 0,0);


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

void DoubleLinkedList::Delete(int pos)
{
	if (count > pos)
	{	if (pos == 0)
		{	// ��������� ����� ������� ��������
			Element* temp = head;
			// ����������� ������ ������� ����� �� 1 �������
			head = head->next;
			// ������� ������ �������
			delete temp;
			return;
		}
		Element* current = head;
		Element* prev = nullptr;
		size_t n = 0;
		while (current != nullptr)
		{	if (pos == n + 1)
			{   // prev - ��������� �� �������, ����� �������� ����� ������� ������� 
				prev = current;
				// current - ������� � ������� index
				current = current->next;
				break;
			}
			// "������������" �� ��������� ������� ������
			current = current->next;
			n++;
		}
		// ������� ������� ����� ��������� � ��������� ����� ����������
		prev->next = current->next;
		// ���� ��������� ��������� �������, �� ��������� ��������� last
		if (tail == current)
			tail = prev;
		// �������� ��������� ��������
		delete current;
		count--;
	}
	else throw exception("Attemp to delete non-existent element");
}


size_t DoubleLinkedList::DeleteAll(char* str)
{
	
	// ���������� �������� ���������
	size_t deletedElementsCount = 0;

	// ���� � ������ ���� ��������
	if (head != nullptr)
	{
		Element* current = head, * prev = nullptr;

		// ���� �� ��������� ������
		while (current != nullptr)
		{
			// ���� ������ �������, ������� ���� �������
			if (strcmp(current->str, str) == 0)
			{
				// ���� ��������� ������ �������
				if (head == current)
				{
					// ��������� ����� ������� ��������
					Element* temp = head;

					// ����������� ������ ������� ����� �� 1 �������
					head = head->next;

					// ������� ������ �������
					delete temp;

					deletedElementsCount++;

					// ���� ����� �������� � ������ �� �������� ���������
					if (head == nullptr)
						return deletedElementsCount;
					else current = head;
				}
				else // ��������� �� ������ �������
				{
					// ������� ������� ����� ��������� � ��������� ����� ����������
					prev->next = current->next;

					// ���� ��������� ��������� �������, �� ��������� ��������� last
					if (tail == current)
					{
						tail = prev;
					}

					// ��������� ����� ������� ��������
					Element* temp = current;

					// ����������� ������ ������� ����� �� 1 �������
					current = current->next;

					// ������� ������ �������
					delete temp;

					deletedElementsCount++;

					// ���� ����� �������� � ������ �� �������� ���������
					if (current == nullptr)
						return deletedElementsCount;
				}
			}
			else // ���� ������� ������� �� ����, �� ������������ �� ���������
			{
				// ��������� ���������� �������
				prev = current;

				// "������������" �� ��������� ������� ������
				current = current->next;
			}
		}

		// ���� ������ ����������, ���������� ���������� �������� ���������
		return deletedElementsCount;
	}
	else return 0;
}

bool DoubleLinkedList::operator== (DoubleLinkedList& second)
{
	Element* current = head;
	Element* current_second = second.head;
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



bool DoubleLinkedList::operator+(DoubleLinkedList& second)
{

	Element* current = this->head;
	if (head == nullptr)
	{
		head = second.head;
	}
	else
	{
		while (current->next != nullptr)
		{
			current = current->next;

		}
		current->next = second.head;
		count++;
	}

	return true;

}

bool DoubleLinkedList::operator+=(DoubleLinkedList& second)
{

	Element* current = this->head;
	if (head == nullptr)
	{
		head = second.head;
	}
	else
	{
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = second.head;
	}
	count++;
	return true;

}

void DoubleLinkedList::Save(const char* filename)
{
	Element* current = head;
	ofstream out(filename, ios::app);
	while (current != nullptr)
	{
		
		out << current->str << "->"<<' ';
		current = current->next;
	}	
	out.close();
}

void DoubleLinkedList::Load(const char* filename)
{
	ifstream in(filename);
	Element* current = head;
	char buffer[200];

	if (!in.good())
		cout << "File can't be found" << std::endl;

	while (!in.eof()) 
	{
		// ������ ����� ���������
		in.getline(buffer, 200);

			// ������ ����� �� ������
		/*in >> buffer;
		cout << buffer << endl;*/
		
	}
	in.close();
	
}

Element* DoubleLinkedList::Find(const char* str)
{
	//Element* node = head;
	//while (node != nullptr)
	//{
	//	if (node->str == str)
	//		return node;
	//	node = node->next;
	//}

	//cout << "No such element in the list \n";
	//return nullptr;


	
	//Element* temp = head;	
	//int count = 0, flag = 0;
	//if (temp == NULL)
	//	return -1;
	//else
	//{	 
	//	while (temp->next != head)
	//	{		
	//		count++;	
	//		if (temp->str == str)
	//		{
	//			flag = 1;
	//			count--;
	//			break;
	//		}
	//	
	//		temp = temp->next;
	//	}
	//	if (temp->str == str)
	//	{
	//		count++;
	//		flag = 1;
	//	}	
	//	if (flag == 1)
	//		cout << "\n" << str << " found at location " <<
	//		count << endl;
	//	else
	//		cout << "\n" << str << " not found" << endl;
	//}
	Element* temp = head;
	
	if (head != NULL) {
		while (temp != NULL) {
			if (temp->str == str) break; 
			else temp = temp->next;
		}
	}
	return temp;
}