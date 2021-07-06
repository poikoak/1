#pragma once
#include <string>
using namespace std;
class Word
{
	friend class Sentence;
	friend class Text;
    int count;
	char* str;
	
	
	
public:
	//Х	конструктор по умолчанию
	Word();
	//Х	конструктор, принимающий строку (char*) и занос€щий еЄ в класс 
	//(если передаЄтс€ несколько слов в строке, хранитс€ только первое слово)
	Word(const char* _title);
	//Х	конструктор копировани€
	Word(const Word& source);
	//Х	деструктор
	~Word();
	//печатает слово на экран
	void Print();
	//возвращает количество символов в слове
	void _lenght();
	void set(const char* _word);
	char* get();
	Word& operator= (const Word& second);
	char& operator[] (const int& pos);



};

