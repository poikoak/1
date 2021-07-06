#pragma once
#include <iostream>
#include <list>
#include "Word.h"
#include "Sentence.h"
#include <fstream>
class Text
{

	//friend class Sentence;
	//friend class Word;
 
	char* str;
	unsigned int count = 0;
	

	list<Sentence*> sentence;
	
public:
	//•	конструктор по умолчанию
	Text();
	//•	конструктор, принимающий строку (char*) и заносящий её в класс 
	//(строка предварительно делится на слова, разделители - пробелы и табуляции)
	Text(const char* text);
	//•	конструктор копирования
	Text(const Text& source);
	//•	деструктор
	~Text();
	//печатает предложение на экран
	void Print();
	//возвращает количество слов в предложении
	void _lenght();
	//заносит новое предложение в класс
	void Set(const char* _replace);
	//возвращает всю строку с предложением
	char* get();
	Text& operator= (Text& second);
	char& operator[] (int pos);
	void PPrint();




	void    SAVE(const char* str);
	void    LOAD(const char* str);
	void	saveWords(const char* filename);
	/*std::ostream& operator<<(std::ostream& os, const Text& second)
	{
		Element* current = second.first;
		while (current != nullptr)
		{
			os << current->str << "\n";
			current = current->next;
		}

		return os;
	}*/


};

