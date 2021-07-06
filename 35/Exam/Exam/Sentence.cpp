#include "Sentence.h"
#include <iostream>
#include <list>
#include "Word.h"
#include <string>
#include <iostream>
#include <conio.h>
using namespace std;

Sentence::Sentence(){
    words.push_back(nullptr);
    this->count = words.size();
    this->str = new char[strlen("Hello new world")+1];
	strcpy(this->str, "Hello new world");
	
	
}

Sentence::Sentence(const char* _title)
{
	//if (_title != nullptr)
	//{
        //this->str = new char[strlen(_title) + 1];
        //if (this->str != nullptr)
        //    strcpy(this->str, _title);
       
        //    //char* token = strtok(str, " ");

        //    //// Keep printing tokens while one of the 
        //    //// delimiters present in str[]. 
        //    //while (token != nullptr)
        //    //{
        //    //    printf("%s\n", token);
        //    //    token = strtok(nullptr, " ");
        //    //}
        //        Word* word = new Word(str);
        //        if (word != nullptr)
        //        {
        //            words.push_back(word);
        //        }
    if (_title != nullptr)
    {
             str = new char[strlen(_title) + 1];
             if (this->str != nullptr)
             strcpy(str, _title);
    }
        char* temp_str= strtok(str, " \t");
        while (str != NULL)
        {
            words.push_back(new Word(str));
            str = strtok(NULL, " \t");
        }
        count = words.size();
   // }
}
	


Sentence::Sentence(Sentence& source)
{
    /*this->str = new char[strlen(source.str) + 1];
    strcpy(this->str, source.str);
    while (str != NULL)
    {
        words.push_back(new Word(str));
        str = strtok(NULL, " \t");
    }
    count = words.size();*/
    this->count = source.count;   
    list<Word*>::iterator pos = source.words.begin();
    while (pos != source.words.end())
    {
        Word* cur = (*pos);
        Word* temp = new Word(cur->get());
        words.push_back(temp);
        pos++;
    }
}

Sentence::~Sentence(){
     
     /* words.erase(words.begin(), words.end());

      if (this->str != nullptr)
          delete[] str;*/
    delete[] this->str;
    list<Word*>::iterator pos = words.begin();
    while (pos != words.end())
    {
        Word* cur = (*pos);
        pos++;
        delete cur;
    }
}
void Sentence::PPrint() { cout << str << " "; }
void Sentence::Print(){ 
      
   // cout << str << endl;
    // перебрать все входящие рёбра и вызвать у них метод Print
    list<Word*>::iterator pos;
    for (pos = words.begin(); pos != words.end(); pos++)
    {      
        (*pos)->Print();
    }
    cout << endl;
}

void Sentence::_lenght()
{
    cout << count << endl;
}

void Sentence::_Set(const char* _replace){

    if (this->str)
    { delete[] str; }
   
    
     words.erase(words.begin(), words.end());
   
    str = new char[strlen(_replace) + 1];
    strcpy(str, _replace);
    char* temp_str = strtok(str, " \t");
    while (str != NULL)
    {
        words.push_back(new Word(str));
        str = strtok(NULL, " \t");
    }
    count = words.size();
   
}

char* Sentence::get()
{
    return str;
}
Sentence& Sentence::operator= (Sentence& second)
{
    if (second.count != 0) {
        if (this->count != second.count)
        {
            words.clear();

            this->count = second.count;
            list<Word*>::iterator pos = second.words.begin();
            while (pos != second.words.end())
            {
                Word* cur = (*pos);
                Word* temp = new Word(cur->get());
                words.push_back(temp);
                pos++;
            }
        }
        else {
            words.clear();
            count = words.size();
        }
    }
    return *this;
}
Word*& Sentence::operator[] (const int& _pos)
{
    int k = 0;
    for ( list<Word*>::iterator pos = words.begin(); pos != words.end();pos++,k++ )
    {
        if (k == _pos)
        {
            return *pos;
        }
    }
   
}