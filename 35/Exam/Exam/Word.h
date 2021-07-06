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
	//�	����������� �� ���������
	Word();
	//�	�����������, ����������� ������ (char*) � ��������� � � ����� 
	//(���� ��������� ��������� ���� � ������, �������� ������ ������ �����)
	Word(const char* _title);
	//�	����������� �����������
	Word(const Word& source);
	//�	����������
	~Word();
	//�������� ����� �� �����
	void Print();
	//���������� ���������� �������� � �����
	void _lenght();
	void set(const char* _word);
	char* get();
	Word& operator= (const Word& second);
	char& operator[] (const int& pos);



};

