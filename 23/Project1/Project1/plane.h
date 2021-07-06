#pragma once
class plane
{


	// массив динамических строк
	char** str;
	size_t maxLinesCount;
	// текущее количество строк
	size_t countstroke;

	// количество резервных ячеек, добавляемых при увеличении размера массива строк
	size_t reserveSize;
	


public:
	
	
	plane(size_t lines);
	~plane();
	void Add(const char* s);
	
	plane& operator = (const plane& s);
	

	void print();

	void SAVE(const char* str);
	void LOAD();
};

