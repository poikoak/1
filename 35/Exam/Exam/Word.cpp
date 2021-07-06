#include "Word.h"
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

Word::Word(){

	this->str = nullptr;
	this->count = 0;
}
Word::Word(const char* _title) {
	//разделители
	//const char* SEPARATORS = ("!?.,;/*-+\n\t ");
	//str = new char[strlen(_title) + 1];
	//strcpy(str, _title);
	//char* ptr = 0;       //Указатель	
	//ptr = strtok(str, SEPARATORS); //Выдираем первое слово из строки
	//strcpy(this->str, ptr);


	/*this->lenght = strlen(_title);
	this->str = new char[lenght + 1];
	strcpy(this->str, _title);
	this->str = strtok(this->str," ");*/
	
	this->count = strlen(_title);
	this->str = new char[count + 1];
	strcpy(this->str, _title);
	for (size_t i = 0; i < strlen(str); i++)
	{
		if (isspace(str[i]))
		{
			char* temp = new char(str[i]);
			str= strtok(str, temp);
			delete temp;
			break;
		}
	}
	count = strlen(str);

	/*if (strlen(_title) != 0)
	{
		char* temp = new char[strlen(_title) + 1];
		strcpy(temp, _title);
		this->str = strtok(temp, " .,;:'?!");
		this->count = strlen(this->str);
		temp = new char[count + 1];
		delete[] temp;
	}
	else
	{
		this->str = nullptr;
		this->count = 0;
	
	}*/
}


Word::Word(const Word& source) {
	/*this->str = new char[strlen(source.str) + 1];
	strcpy(this->str, source.str);*/


	this->count = strlen(source.str);
	this->str = new char[count + 1];
	strcpy(this->str, source.str);

}
Word::~Word() 
{
	delete[] this->str;
}

void Word::Print(){
	cout << str <<" ";
}
void Word::_lenght(){

	/*for (unsigned int i = 0; i < strlen(str); i++) {
		count++;
	}
	cout<<"Number of characters in a word = " << count << endl;*/
	this->count = strlen(str);
	cout<< this->count <<endl;

}
void Word::set(const char* _replace){
	/*if (this->str) { delete[] str; }
	this->str = new char[strlen(str) + 1];
	strcpy(this->str, _replace);*/
	
	if (this->str) { delete[] str; }
	this->count = strlen(_replace);
	this->str = new char[count + 1];
	strcpy(this->str, _replace);
	this->str = strtok(this->str, " ");

}
char* Word::get()
{
	return this->str;
}
Word& Word::operator= (const Word& second){
	if (this->count != second.count)
	{
		delete[] this->str;
		this->count = second.count;
		this->str = new char[this->count + 1];
		strcpy(this->str, second.str);
	}
	else
	{
		strcpy(this->str, second.str);
	}
	return *this;
}
char& Word::operator[] (const int& pos){
	if (pos >= 0 && pos < this->count)
	{		
		return this->str[pos];
	}
	
}