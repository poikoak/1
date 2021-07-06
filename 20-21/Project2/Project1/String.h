#pragma once
class String
{
protected:
	

	// объявление статического поля класса, счетчик
	static int count;
	////////////////


	// массив динамических строк
	char** str;
	size_t maxLinesCount;
	// текущее количество строк
	size_t countstroke;

	// количество резервных ячеек, добавляемых при увеличении размера массива строк
	size_t reserveSize;

	
	void StretchLines();
public:
	String();
	String(size_t lines);	
	~String();
	void Add(const char* s);
	void Print();
	


	// объявление статического метода
	static int GetCount();

	void SAVE(const char* s);
	void LOAD();



	String& operator+= (String& t);
	String& operator-= (String& t);

	// оператор запускается при попытке создания объекта при помощи стандартного оператора new
	void* operator new(size_t);

	// оператор запускается при попытке удаления объекта при помощи стандартного оператора delete
	void operator delete(void* p);

	// оператор запускается при попытке создания объекта при помощи стандартного оператора new
	void* operator new[](size_t);

	// оператор запускается при попытке удаления объекта при помощи стандартного оператора delete
	void operator delete[](void* p);
};

