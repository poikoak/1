#include "DoubleLinkedList.h"
#include <iostream>
#include <fstream>

DoubleLinkedList::DoubleLinkedList()
{
	first = last = nullptr;
	count = 0;
}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& second)
{
	first = last = nullptr;
	count = 0;
	Element* current = second.first;

	while (current != nullptr)
	{
		// �������� ������� ������� ����������� ������ � ����� ������
		Add(current->str);

		// "������������" �� ��������� ������� ������
		current = current->next;
	}
}

DoubleLinkedList::~DoubleLinkedList()
{
	Element* current = first;

	while (current != nullptr)
	{
		Element* temp = current;

		// "������������" �� ��������� ������� ������
		current = current->next;

		delete temp;
	}
}

void DoubleLinkedList::Add(std::string str)
{
	// ������ ����, �� next � prev ����� 0
	if (first == nullptr)
	{
		first = last = new Element(str, 0, 0);
	}
	else // ������ �� ����
	{
		// ������� ����� ������� ������
		Element* elem = new Element(str, 0, 0);

		// ��������� ������� ������ ��������� �� ����� ��������� �������
		last->next = elem;
		// ����� ��������� ������� ������ ��������� �� ���������� �������, � elem->next �������� 0
		elem->prev = last;

		// �������� ��������� �� ��������� �������
		last = elem;
	}

	// ��������� ���������� ��������� �� 1
	count++;
}

void DoubleLinkedList::Print()
{
	Element* current = first;

	while (current != nullptr)
	{
		// ������� �� ����� ���������� �������� �������� ������
		std::cout << current->str << std::endl;

		// "������������" �� ��������� ������� ������
		current = current->next;
	}

	std::cout << std::endl;
}

void DoubleLinkedList::AddFirst(std::string str)
{
	// ������ ����, �� next � prev ����� 0
	if (first == nullptr)
	{
		first = last = new Element(str, 0, 0);
	}
	else // ������ �� ����
	{
		// ������� ����� ������� ������
		Element* elem = new Element(str, 0, 0);

		// ������ ������ ������� ������ ��������� �� ����� ��������� �������
		first->prev = elem;
		// ����� ��������� ������� ������ ��������� �� ������ ������ �������, � elem->prev �������� 0
		elem->next = first;

		// �������� ��������� �� ������ �������
		first = elem;
	}

	// ��������� ���������� ��������� �� 1
	count++;
}

void DoubleLinkedList::PrintBack()
{
	Element* current = last;

	while (current != nullptr)
	{
		// ������� �� ����� ���������� �������� �������� ������
		std::cout << current->str << std::endl;

		// "������������" �� ���������� ������� ������
		current = current->prev;
	}

	std::cout << std::endl;
}

Element* DoubleLinkedList::Find(std::string str)
{
	Element* current = first;
	while (current != nullptr)
	{
		// ������������� ��������, ���� ����� - ����������
		return (current->str == str) ? current : 0;
	}
}

void DoubleLinkedList::Clear()
{
	Element* current = first;

	while (current != nullptr)
	{
		//std::cout << current << std::endl;
		current->str = "\0";
		current = current->next;
	}
	first = last;
}

void DoubleLinkedList::Insert(std::string str, size_t pos)
{
	if (count > pos)
	{
		// ������� ����� ������� ������
		Element* elem = new Element(str, 0, 0);

		// ���� ������ ������ �������
		if (pos == 0)
		{
			AddFirst(str);
			return;
		}

		// ���� ������ ��������� �������
		if (pos + 1 == count)
		{
			Add(str);
			return;
		}

		// ���� ��������� �� � ������, �� � ��������� �������
		Element* current = first;
		size_t n = 0;

		while (current != nullptr)
		{
			if (pos == n)
			{
				//�������� ��� ���������� �������� (prev)
				current->prev->next = elem;

				// ��������� ��� ������������ �������� (prev&next)
				elem->next = current->next;
				elem->prev = current;

				//�������� ��� �������� (�� ��� ����������) (next)
				current->next = elem;
				break;
			}

			// ���� ������� �� �������������, �� "������������" �� ��������� ������� ������
			current = current->next;
			n++;
		}

		count++;
	}
	else throw std::exception("Attemp to insert to empty list!!!");
}

void DoubleLinkedList::Delete(size_t pos)
{
	if (count > pos)
	{
		//���� ������� ������
		if (pos == 0)
		{
			// ��������� ����� ������� ��������
			Element* current = first;
			// ����������� ������ ������� ����� �� 1 ���, � ���������� ����� ������ �������
			first = first->next;
			first->prev = 0;

			// ������� ���������� ��������
			delete current;

			return;
		}

		// ���� ������� ���������
		if (pos + 1 == count)
		{
			// ��������� ����� ���������� ��������
			Element* current = first;
			// ����������� ��������� ������� ����� �� 1 ���, � ��������� ����� ������ �������
			last = last->prev;
			last->next = 0;

			// ������� ���������� ��������
			delete current;

			return;
		}

		// ���� ������� �� ������, �� ���������
		Element* current = first;
		size_t n = 0;

		while (current != nullptr)
		{
			if (pos == n)
			{
				// ����������� �������� ������� �� �������� - ���������� ����������
				current->prev->next = current->next;
				// ���������� �������� ������� �� �������� - ���������� �����������
				current->next->prev = current->prev;

				break;
			}

			// ���� ������� ��� �� �������, "������������" �� ��������� ������� ������
			current = current->next;
			n++;
		}

		// �������� ���������� ��������
		delete current;

		count--;
	}
	else throw std::exception("Attemp to delete non-existent element");
}

size_t DoubleLinkedList::Delete_All(std::string str)
{
	// ���������� �������� ���������
	size_t deletedElementsCount = 0;

	// ���� � ������ ���� ��������
	if (first != nullptr)
	{
		Element* current = first;

		// ���� �� ��������� ������
		while (current != nullptr)
		{
			// ���� ������ �������, ������� ���� �������
			if (current->str == str)
			{
				// ���� ��������� ������ �������
				if (first == current)
				{
					// ��������� ����� ������� ��������
					Element* temp = first;

					// ����������� ������ ������� ����� �� 1 ���
					first = first->next;
					first->prev = 0;

					// ������� ������ �������
					delete temp;

					deletedElementsCount++;

					// ���� ����� �������� � ������ �� �������� ���������
					if (first == nullptr)
						return deletedElementsCount;
					else current = first;
				}
				else if (last == current)
				{
					// ��������� ����� ���������� ��������
					Element* temp = last;

					// ����������� ���������� ������� ����� �� 1 ���
					last = last->next;
					last->next = 0;

					// ������� ������ �������
					delete temp;

					deletedElementsCount++;

					// ���� ����� �������� � ������ �� �������� ���������
					if (current == nullptr)
						return deletedElementsCount;
				}
				else // ��������� �� ������, �� ��������� �������
				{
					// ��������� ����� �������� ��������
					Element* temp = current;

					// ����������� �������� ������� �� �������� - ���������� ����������
					current->prev->next = current->next;
					// ���������� �������� ������� �� �������� - ���������� �����������
					current->next->prev = current->prev;

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
				// "������������" �� ��������� ������� ������
				current = current->next;
			}
		}

		// ���� ������ ����������, ���������� ���������� �������� ���������
		return deletedElementsCount;
	}
	else return 0;
}

size_t DoubleLinkedList::Get_Count(std::string str)
{
	size_t result = 0;
	Element* current = first;

	while (current != nullptr)
	{
		if (current->str == str)
			result++;

		// "������������" �� ��������� ������� ������
		current = current->next;
	}
	
	return result;
}

DoubleLinkedList& DoubleLinkedList::operator=(DoubleLinkedList& second)
{
	// �������� ������ ��������� ������
	Element* current = first;

	while (current != nullptr)
	{
		Element* temp = current;

		// "������������" �� ��������� ������� ������
		current = current->next;

		delete temp;
	}

	first = last = nullptr;

	// ���������� ����� ���������
	current = second.first;

	while (current != nullptr)
	{
		Add(current->str);

		// "������������" �� ��������� ������� ������
		current = current->next;
	}

	return *this;
}

std::string DoubleLinkedList::operator[](int pos)
{
	int n = 0;
	Element* current = first;

	while (current != nullptr)
	{
		if (pos == n)
			return current->str;

		// "������������" �� ��������� ������� ������
		current = current->next;

		n++;
	}

	throw std::exception("Incorrect index!!!");
}

bool DoubleLinkedList::operator==(DoubleLinkedList& second)
{
	Element* current_first = first;
	Element* current_second = second.first;
	// ������� ������ ���������
	int count_equ = 0;

	while (current_first != nullptr)
	{
		if (current_first->str == current_second->str)
		{
			count_equ++;
		}
		else
		{
			return false;
		}
		current_first = current_first->next;
		current_second = current_second->next;
	}
	return (count_equ == count) ? true : false;
}

DoubleLinkedList& DoubleLinkedList::operator+(Element& elem)
{
	DoubleLinkedList* result = new DoubleLinkedList();
	Element* current = first;

	while (current != nullptr)
	{
		result->Add(current->str);
		current = current->next;
	}

	result->Add(elem.str);
	return *result;
}

DoubleLinkedList& DoubleLinkedList::operator+(DoubleLinkedList& second)
{
	DoubleLinkedList* result = new DoubleLinkedList();
	Element* current = first;

	while (current != nullptr)
	{
		result->Add(current->str);
		current = current->next;
	}

	current = second.first;
	while (current != nullptr)
	{
		result->Add(current->str);
		current = current->next;
	}
	return *result;
}

DoubleLinkedList& DoubleLinkedList::operator+=(DoubleLinkedList& second)
{
	Element* current = second.first;

	while (current != nullptr)
	{
		Add(current->str);
		current = current->next;
	}

	return *this;
}

DoubleLinkedList& DoubleLinkedList::operator++()
{
	Element* current = first;
	
	while (current != nullptr)
	{
		current->str = current->str + "!";
		current = current->next;
	}
	
	return *this;
}

DoubleLinkedList& DoubleLinkedList::operator--()
{
	Element* current = first;

	while (current != nullptr)
	{
		current->str.erase(0, 1);
		current = current->next;
	}

	return *this;
}

DoubleLinkedList DoubleLinkedList::operator++(int n)
{
	DoubleLinkedList result = *this;
	Element* current = first;
	
	while (current != nullptr)
	{
		current->str = "!" + current->str ;
		current = current->next;
	}

	return result;
}

DoubleLinkedList DoubleLinkedList::operator--(int n)
{
	Element* current = first;

	while (current != nullptr)
	{
		//current->str = current->str.substr(0, current->str.length() - 1);
		current->str.erase(current->str.length() - 1, current->str.length());
		current = current->next;
	}

	return *this;
}

void DoubleLinkedList::Save(const char* filename)
{
	std::fstream save(filename, std::ios::out);
	if (save)
	{
		// ����������� ��������� ������ �� ���������, � ���������� ������ ������ �������, � ��������� ������� Add()
		Element* current = first;
		while (current != nullptr)
		{
			// ��������� ������ ��������� ������
			save << current->str << "\n";
			// "������������" �� ��������� ������� ������
			current = current->next;
		}
		save.close();

		// ������� ��������� current
		delete current;
		// �������� ������������ ����� ���������� �������� � �� �� ���������
		//system("test.txt");
	}
	else throw std::exception("!Error saving file.");
}

void DoubleLinkedList::Load(const char* filename)
{
	std::fstream load(filename, std::ios::in);
	if (load)
	{
		// ������ ������, ������� � �������� � ������ �����������, ���� �� ���������� ����
		char* temp = new char[500];

		while (!load.eof())
		{
			load >> temp;
			Add(temp);
		}

		delete[] temp;
	}
	else throw std::exception("!Error load file.");
}

std::ostream& operator<<(std::ostream& os, const DoubleLinkedList& second)
{
	Element* current = second.first;
		while (current != nullptr)
		{
			os << current->str << "\n";
			current = current->next;
		}

	return os;
}

std::istream& operator>>(std::istream& is, DoubleLinkedList& second)
{
	Element* current = second.first;
	while (current != nullptr)
	{
		is >> current->str;
		current = current->next;
	}

	return is;
}
