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
		// добавить текущий элемент копируемого списка в новый список
		Add(current->str);

		// "перепрыгнуть" на следующий элемент списка
		current = current->next;
	}
}

DoubleLinkedList::~DoubleLinkedList()
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

void DoubleLinkedList::Add(std::string str)
{
	// список пуст, то next и prev равно 0
	if (first == nullptr)
	{
		first = last = new Element(str, 0, 0);
	}
	else // список не пуст
	{
		// создать новый элемент списка
		Element* elem = new Element(str, 0, 0);

		// последний элемент списка указывает на новый созданный элемент
		last->next = elem;
		// новый созданный элемент списка указывает на предыдущий элемент, а elem->next остается 0
		elem->prev = last;

		// поменять указатель на последний элемент
		last = elem;
	}

	// увеличить количество элементов на 1
	count++;
}

void DoubleLinkedList::Print()
{
	Element* current = first;

	while (current != nullptr)
	{
		// вывести на экран содержимое текущего элемента списка
		std::cout << current->str << std::endl;

		// "перепрыгнуть" на следующий элемент списка
		current = current->next;
	}

	std::cout << std::endl;
}

void DoubleLinkedList::AddFirst(std::string str)
{
	// список пуст, то next и prev равно 0
	if (first == nullptr)
	{
		first = last = new Element(str, 0, 0);
	}
	else // список не пуст
	{
		// создать новый элемент списка
		Element* elem = new Element(str, 0, 0);

		// бывший первый элемент списка указывает на новый созданный элемент
		first->prev = elem;
		// новый созданный элемент списка указывает на бывший первый элемент, а elem->prev остается 0
		elem->next = first;

		// поменять указатель на первый элемент
		first = elem;
	}

	// увеличить количество элементов на 1
	count++;
}

void DoubleLinkedList::PrintBack()
{
	Element* current = last;

	while (current != nullptr)
	{
		// вывести на экран содержимое текущего элемента списка
		std::cout << current->str << std::endl;

		// "перепрыгнуть" на предыдущий элемент списка
		current = current->prev;
	}

	std::cout << std::endl;
}

Element* DoubleLinkedList::Find(std::string str)
{
	Element* current = first;
	while (current != nullptr)
	{
		// Сравнивниваем элементы, если равны - возвращаем
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
		// Создать новый элемент списка
		Element* elem = new Element(str, 0, 0);

		// Если указан первый элемент
		if (pos == 0)
		{
			AddFirst(str);
			return;
		}

		// Если указан последний элемент
		if (pos + 1 == count)
		{
			Add(str);
			return;
		}

		// Если добавляем ни в первый, ни в последний элемент
		Element* current = first;
		size_t n = 0;

		while (current != nullptr)
		{
			if (pos == n)
			{
				//Параметр для следующего элемента (prev)
				current->prev->next = elem;

				// Параметры для вставляемого элемента (prev&next)
				elem->next = current->next;
				elem->prev = current;

				//Параметр для текущего (он уже предыдущий) (next)
				current->next = elem;
				break;
			}

			// если условие не удовлетворяет, то "перепрыгнуть" на следующий элемент списка
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
		//Если элемент первый
		if (pos == 0)
		{
			// запомнить адрес первого элемента
			Element* current = first;
			// переместить первый элемент вперёд на 1 шаг, а предыдущий адрес станет нулевым
			first = first->next;
			first->prev = 0;

			// удалить выбранного элемента
			delete current;

			return;
		}

		// Если элемент последний
		if (pos + 1 == count)
		{
			// запомнить адрес последнего элемента
			Element* current = first;
			// переместить последний элемент назад на 1 шаг, а следующий адрес станет нулевым
			last = last->prev;
			last->next = 0;

			// удалить выбранного элемента
			delete current;

			return;
		}

		// Если элемент ни первый, ни последний
		Element* current = first;
		size_t n = 0;

		while (current != nullptr)
		{
			if (pos == n)
			{
				// Предыдущему элементу передаём от текущего - координаты следующего
				current->prev->next = current->next;
				// Следующему элементу передаём от текущего - координаты предыдущего
				current->next->prev = current->prev;

				break;
			}

			// если условие еще не найдено, "перепрыгнуть" на следующий элемент списка
			current = current->next;
			n++;
		}

		// удаление выбранного элемента
		delete current;

		count--;
	}
	else throw std::exception("Attemp to delete non-existent element");
}

size_t DoubleLinkedList::Delete_All(std::string str)
{
	// количество удалённых элементов
	size_t deletedElementsCount = 0;

	// если в списке есть элементы
	if (first != nullptr)
	{
		Element* current = first;

		// цикл по элементам списка
		while (current != nullptr)
		{
			// если найден элемент, который надо удалить
			if (current->str == str)
			{
				// если удаляется первый элемент
				if (first == current)
				{
					// запомнить адрес первого элемента
					Element* temp = first;

					// переместить первый элемент вперёд на 1 шаг
					first = first->next;
					first->prev = 0;

					// удалить старый элемент
					delete temp;

					deletedElementsCount++;

					// если после удаления в списке не осталось элементов
					if (first == nullptr)
						return deletedElementsCount;
					else current = first;
				}
				else if (last == current)
				{
					// запомнить адрес последнего элемента
					Element* temp = last;

					// переместить проследний элемент назад на 1 шаг
					last = last->next;
					last->next = 0;

					// удалить старый элемент
					delete temp;

					deletedElementsCount++;

					// если после удаления в списке не осталось элементов
					if (current == nullptr)
						return deletedElementsCount;
				}
				else // удаляется ни первый, ни последний элемент
				{
					// запомнить адрес текущего элемента
					Element* temp = current;

					// Предыдущему элементу передаём от текущего - координаты следующего
					current->prev->next = current->next;
					// Следующему элементу передаём от текущего - координаты предыдущего
					current->next->prev = current->prev;

					// удалить старый элемент
					delete temp;

					deletedElementsCount++;

					// если после удаления в списке не осталось элементов
					if (current == nullptr)
						return deletedElementsCount;
				}
			}
			else // если элемент удалять не надо, то перепрыгнуть на следующий
			{
				// "перепрыгнуть" на следующий элемент списка
				current = current->next;
			}
		}

		// весь список просмотрен, возвратить количество удалённых элементов
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

		// "перепрыгнуть" на следующий элемент списка
		current = current->next;
	}
	
	return result;
}

DoubleLinkedList& DoubleLinkedList::operator=(DoubleLinkedList& second)
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

std::string DoubleLinkedList::operator[](int pos)
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

	throw std::exception("Incorrect index!!!");
}

bool DoubleLinkedList::operator==(DoubleLinkedList& second)
{
	Element* current_first = first;
	Element* current_second = second.first;
	// Счетчик равных элементов
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
		// Колличество элементов списка не сохраняем, в дальнейшем считаю каждый элемент, а посчитает функция Add()
		Element* current = first;
		while (current != nullptr)
		{
			// Сохраняем данные элементов списка
			save << current->str << "\n";
			// "перепрыгнуть" на следующий элемент списка
			current = current->next;
		}
		save.close();

		// Удаляем временный current
		delete current;
		// Открытие сохраненного файла программой заданной в ОС по умолчанию
		//system("test.txt");
	}
	else throw std::exception("!Error saving file.");
}

void DoubleLinkedList::Load(const char* filename)
{
	std::fstream load(filename, std::ios::in);
	if (load)
	{
		// Создаю буффер, копирую и добавляю в список поэлементно, пока не закончится файл
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
