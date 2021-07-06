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
	//�	����������� �� ���������
	Sentence();
	//�	�����������, ����������� ������ (char*) � ��������� � � ����� 
	//(������ �������������� ������� �� �����, ����������� - ������� � ���������)
	Sentence(const char* _title);
	//�	����������� �����������
	Sentence( Sentence& source);
	//�	����������
	~Sentence();
	//�������� ����������� �� �����
	void Print();
	//���������� ���������� ���� � �����������
	void _lenght();
	//������� ����� ����������� � �����
	void _Set(const char* _replace);
	//���������� ��� ������ � ������������
	char* get();
	Sentence& operator= (Sentence& second);
	Word*& operator[] (const int& _pos);

	void PPrint();


};

