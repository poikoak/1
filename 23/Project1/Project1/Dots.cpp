#include "plane.h"
#include <iostream>
using namespace std;




plane::plane(size_t lines)
{
	countstroke = 0;
	reserveSize = 5;
	maxLinesCount = lines;

	// �������� ������� ���������� �� ������
	str = new char* [maxLinesCount];
	this->str = str;

}

plane::~plane()

{ // �������� ����������� �����
	for (size_t i = 0; i < countstroke; i++)
	{
		delete[] str[i];
	}

	// �������� ������� ����������
	delete[] str;

	cout << "Destr" << endl;
}

void plane::print()
{
	
	for (size_t i = 0; i < countstroke; i++)
	{
		cout << this->str[i] << endl;
	}
	cout << endl;

}

void plane::Add(const char* s)
{
	// ��������� ������ ��� ����� (���������) ������
	str[countstroke] = new char[strlen(s) + 1];

	// ����������� ������ � ������ �����
	strcpy(str[countstroke], s);

	// ��������� ���������� ����������� �����
	countstroke++;




	FILE* file = fopen("file1.txt", "wb");
	if (file != nullptr)
	{
		for (size_t i = 0; i < countstroke; i++)
		{
			fprintf(file, "%1s", str[i]);
			fprintf(file, "\n");
		}
		
	}
	fclose(file);

	//cout<<"fail saved" << endl;

	

}
void plane::LOAD()
{

	FILE* file = fopen("file1.txt", "rb");
	if (file != nullptr)
	{
		fseek(file, 0, SEEK_END);
		size_t FileSize = ftell(file);
		fseek(file, 0, SEEK_SET);
		char* buffer = new char[FileSize];
		fread(buffer, sizeof(char), FileSize, file);
		fclose(file);
		for (size_t i = 0; i < countstroke; i++)
		{
			fprintf(file, "%1s", str[i]);
		}
		printf("\n");


		delete[] buffer;

	}
}



plane& plane::operator= (const plane& source)
{
	// ���� � �������� ��������� ������ ���������� ����� (������� ���������� ����� ������ �����)
	if (maxLinesCount != source.maxLinesCount)
	{
		// �������� ����������� �����
		for (size_t i = 0; i < countstroke; i++)
		{
			delete[] str[i];
		}

		// �������� ������� ����������
		delete[] str;

		// ����������� ���� ������
		maxLinesCount = source.maxLinesCount;
		countstroke = source.countstroke;

		// �������� ������� ���������� �� ������
		str = new char* [maxLinesCount];
	}

	// ����������� ����� �� ��������� ������� � ��������������
	for (size_t i = 0; i < countstroke; i++)
	{
		// ��������� ������ ��� ����� (���������) ������
		str[i] = new char[strlen(source.str[i]) + 1];

		// ����������� ������ �� ��������� ������� � ����� ������
		strcpy(str[i], source.str[i]);
	}

	return *this;
}


