#pragma once
class plane
{


	// ������ ������������ �����
	char** str;
	size_t maxLinesCount;
	// ������� ���������� �����
	size_t countstroke;

	// ���������� ��������� �����, ����������� ��� ���������� ������� ������� �����
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

