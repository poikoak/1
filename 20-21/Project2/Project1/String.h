#pragma once
class String
{
protected:
	

	// ���������� ������������ ���� ������, �������
	static int count;
	////////////////


	// ������ ������������ �����
	char** str;
	size_t maxLinesCount;
	// ������� ���������� �����
	size_t countstroke;

	// ���������� ��������� �����, ����������� ��� ���������� ������� ������� �����
	size_t reserveSize;

	
	void StretchLines();
public:
	String();
	String(size_t lines);	
	~String();
	void Add(const char* s);
	void Print();
	


	// ���������� ������������ ������
	static int GetCount();

	void SAVE(const char* s);
	void LOAD();



	String& operator+= (String& t);
	String& operator-= (String& t);

	// �������� ����������� ��� ������� �������� ������� ��� ������ ������������ ��������� new
	void* operator new(size_t);

	// �������� ����������� ��� ������� �������� ������� ��� ������ ������������ ��������� delete
	void operator delete(void* p);

	// �������� ����������� ��� ������� �������� ������� ��� ������ ������������ ��������� new
	void* operator new[](size_t);

	// �������� ����������� ��� ������� �������� ������� ��� ������ ������������ ��������� delete
	void operator delete[](void* p);
};

