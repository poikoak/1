#include "Text.h"
#include "Sentence.h"
#include "Word.h"
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <conio.h>
#include <io.h>
#include<map>
using namespace std;


#include <sstream>

Text::Text() {
    sentence.push_back(nullptr);
    this->count = sentence.size();
    this->str = new char[strlen("Hello new world.Master flomaster! Chamba mamba?") + 1];
    strcpy(this->str, "Hello new world");


}

Text::Text( const char* _title)
{
   /* char seps[] = ".!?";
    char* token;*/
 
   // token = strtok(str, seps);
  /*  while (token != NULL)
    {       
        sentence.push_back(token);
        token = strtok(NULL, seps);
    }
    count = sentence.size();
  
   
    for (int i = 0; i < sentence.size(); ++i)
        cout << token[i] << "\n";
    cout << "\n\n\n";*/

    /*vector<string> vec_String_Lines;
    token = strtok(str, seps);

    cout << "Extracting and storing data in a vector..\n\n\n";

    while (token != NULL)
    {
        vec_String_Lines.push_back(token);
        token = strtok(NULL, seps);
    }
    cout << "Displaying end result in  vector line storage..\n\n";

    for (int i = 0; i < vec_String_Lines.size(); ++i)
        cout << vec_String_Lines[i] << "\n";
    cout << "\n\n\n";*/



    //  this->text = text;
    //int len = text.length();
    //string tab = "   ";
    //string formatted = tab;

    //int i = -1;
    //while (++i < len)
    //{
    //    formatted += text[i];       //рутина - копируем символ в новую строку
    //    if (text[i] == '.'|| text[i] == '!' || text[i] == '?')     //если дошли до точки
    //    {
    //        formatted += "\n";  //вставляем перевод строки
    //        formatted += tab;   //вставляем табуляцию

    //        if (i + 1 < len && text[i + 1] == ' ')    //игнорируем пробел после точки, если он там есть
    //            ++i;
    //       
    //    }
    //}
   // std::cout << formatted;
    
    /*if (_title != nullptr)
    {
        str = new char[strlen(_title) + 1];
        if (this->str != nullptr)
            strcpy(str, _title);
    }
    for (size_t i = 0; i < strlen(str); i++)
    {
        
        if (str[i] == '.' || str[i] == '!' || str[i] == '?')
        {
            char* temp = new char(str[i]);
            str = strtok(this->str, temp);
            break;
            
        }
    }*/
    char SEPARATORS[] = ".!?";
    list<char*>t;
    char* first = new char[strlen(_title) + 1];
    strcpy(first, _title);
    char* temp = strtok(first, SEPARATORS);
    while (temp != NULL)
    {
        char* second = new char[strlen(temp) + 1];
        strcpy(second, temp);
        t.push_back(second);        
        temp = strtok(NULL, SEPARATORS);
    }

    delete[] first;

    for (auto pos = t.begin(); pos != t.end(); pos++)
    {
        sentence.push_back(new Sentence(*pos));
    }
    count = sentence.size();
}



Text::Text(const Text& source)
{
    char SEPARATORS[] = ".!?";
    list<char*>t;
    char* first = new char[strlen(source.str) + 1];
    strcpy(first, source.str);
    char* temp = strtok(first, SEPARATORS);
    while (temp != NULL)
    {
        char* second = new char[strlen(temp) + 1];
        strcpy(second, temp);
        t.push_back(second);
        //lenT++;
        temp = strtok(NULL, SEPARATORS);
    }

    delete[] first;

    for (auto pos = t.begin(); pos != t.end(); pos++)
    {
        sentence.push_back(new Sentence(*pos));
    }
    count = sentence.size();
}

Text::~Text() {

    sentence.erase(sentence.begin(), sentence.end());

    if (this->str != nullptr)
        delete[] str;
}
void Text::PPrint() { cout << str; }
void Text::Print() {

   
    list<Sentence*>::iterator pos;
    for (pos = sentence.begin(); pos != sentence.end(); pos++)
    {
      
        (*pos)->Print();
        cout << endl;
    }
 //cout << endl;
  /*  for (auto pos = sentence.begin(); pos != sentence.end(); pos++)
    {
        (*pos)->Print();
    }*/
    /*for (list<Sentence*>::iterator iter = sentence.begin(); iter != sentence.end(); iter++)
    {
        cout << *iter << endl;
        for (auto& str : sentence)
            std::cout << str << "\n";
    }*/
}

void Text::_lenght()
{
    cout << count << endl;
}

void Text::Set(const char* _replace) {

    //if (this->str)
    //{
    //    delete[] str;
    //}
    //sentence.erase(sentence.begin(), sentence.end());

    //char SEPARATORS[] = ".!?";
    //list<char*>t;
    //char* first = new char[strlen(_replace) + 1];
    //strcpy(first, _replace);
    //char* temp = strtok(first, SEPARATORS);
    //while (temp != NULL)
    //{
    //    char* second = new char[strlen(temp) + 1];
    //    strcpy(second, temp);
    //    t.push_back(second);
    //    temp = strtok(NULL, SEPARATORS);
    //    delete[] second;
    //}

    //delete[] first;

    //for (auto pos = t.begin(); pos != t.end(); pos++)
    //{
    //    sentence.push_back(new Sentence(*pos));
    //}
    //count = sentence.size();
    sentence.clear();
    Sentence word_temp;
    if (strlen(_replace) != 0)
    {
        char* temp = new char[strlen(_replace) + 1];
        char* first_sentence = new char[strlen(_replace) + 1];
        strcpy(temp, _replace);
        //Выделение первого предложения
        first_sentence = strtok(temp, ".?!;");
        // Выделение и добавление в список - слов
        temp = strtok(first_sentence, " \t");
        while (temp != nullptr)
        {
            word_temp._Set(temp);
            sentence.push_back(new Sentence(word_temp));
            temp = strtok(nullptr, " \t");
        }
        this->count = sentence.size();

        delete[] temp;
        delete[] first_sentence;
    }
    else
    {
        sentence.push_back(new Sentence(word_temp));
        this->count = sentence.size();
    }
}

char* Text::get()
{
    return str;
}
Text& Text::operator= (Text& second)
{

    if (second.str != 0)
    {
        if (this->count != second.count)
        {
            sentence.clear();
               
                this->count = second.count;
                list<Sentence*>::iterator pos = second.sentence.begin();
                while (pos != second.sentence.end())
                {
                    Sentence* cur = (*pos);
                        Sentence* temp = new Sentence(cur->get());
                        sentence.push_back(temp);
                    pos++;
                }
        }
        else {
            sentence.clear();
            count = sentence.size();
        }
    }
    return *this;




    return *this;
}
char& Text::operator[] (int pos)
{

    return this->str[pos];
}


void    Text::SAVE(const char* str){
     
// sentence.sort(); //Сортирует списки, т-к unique работает только с отсортированными списками

   //// sentence.unique();
   // ofstream Entr(str);
   // if (Entr)
   // {
   //         
   //     list<Sentence*>::iterator pos;
   //     for (pos = sentence.begin(); pos != sentence.end(); pos++)
   //     {
   //       
   //         Entr << (*pos) << endl;

   //         for (list<Sentence*>::const_iterator i = sentence.begin(); i != sentence.end(); i++)
   //         {
   //             Entr << *i << endl;
   //         }
   //         Entr.close();
   //     }
   // }
   // else
   //     cout << "Ошибка!\n";

   
  
}
void    Text::LOAD(const char* str){

   


}
void	Text::saveWords(const char* filename){





}