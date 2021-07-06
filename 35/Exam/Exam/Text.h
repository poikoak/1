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
	//�	����������� �� ���������
	Text();
	//�	�����������, ����������� ������ (char*) � ��������� � � ����� 
	//(������ �������������� ������� �� �����, ����������� - ������� � ���������)
	Text(const char* text);
	//�	����������� �����������
	Text(const Text& source);
	//�	����������
	~Text();
	//�������� ����������� �� �����
	void Print();
	//���������� ���������� ���� � �����������
	void _lenght();
	//������� ����� ����������� � �����
	void Set(const char* _replace);
	//���������� ��� ������ � ������������
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

