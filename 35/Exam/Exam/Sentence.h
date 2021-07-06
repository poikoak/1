#pragma once
#include <list>
#include "Word.h"

class Sentence
{
	//friend class Text;
	//friend class Word;
	
	char* str;
	unsigned int count = 0;

	list<Word*> words;
	
public:
	//•	конструктор по умолчанию
	Sentence();
	//•	конструктор, принимающий строку (char*) и заносящий её в класс 
	//(строка предварительно делится на слова, разделители - пробелы и табуляции)
	Sentence(const char* _title);
	//•	конструктор копирования
	Sentence( Sentence& source);
	//•	деструктор
	~Sentence();
	//печатает предложение на экран
	void Print();
	//возвращает количество слов в предложении
	void _lenght();
	//заносит новое предложение в класс
	void _Set(const char* _replace);
	//возвращает всю строку с предложением
	char* get();
	Sentence& operator= (Sentence& second);
	Word*& operator[] (const int& _pos);

	void PPrint();


};

