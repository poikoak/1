#include "plane.h"
#include <iostream>
using namespace std;




plane::plane(size_t lines)
{
	countstroke = 0;
	reserveSize = 5;
	maxLinesCount = lines;

	// создание массива указателей на строки
	str = new char* [maxLinesCount];
	this->str = str;

}

plane::~plane()

{ // удаление заполненных строк
	for (size_t i = 0; i < countstroke; i++)
	{
		delete[] str[i];
	}

	// удаление массива указателей
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
	// выделение памяти для новой (последней) строки
	str[countstroke] = new char[strlen(s) + 1];

	// скопировать строку в массив строк
	strcpy(str[countstroke], s);

	// увеличить количество заполненных строк
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
	// если в объектах находится разное количество строк (массивы указателей имеют разную длину)
	if (maxLinesCount != source.maxLinesCount)
	{
		// удаление заполненных строк
		for (size_t i = 0; i < countstroke; i++)
		{
			delete[] str[i];
		}

		// удаление массива указателей
		delete[] str;

		// скопировать поля класса
		maxLinesCount = source.maxLinesCount;
		countstroke = source.countstroke;

		// создание массива указателей на строки
		str = new char* [maxLinesCount];
	}

	// копирование строк из исходного массива в результирующий
	for (size_t i = 0; i < countstroke; i++)
	{
		// выделение памяти для новой (последней) строки
		str[i] = new char[strlen(source.str[i]) + 1];

		// скопировать строку из исходного объекта в новый объект
		strcpy(str[i], source.str[i]);
	}

	return *this;
}


