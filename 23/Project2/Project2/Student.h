#pragma once

#include "Person.h"



class Student : public Person
{

    int day;
    int month;
    int year;
    int age;
    


public:
    void SetDay(int day);
    int GetDay();

    void SetMonth(int month);
    int GetMonth();
   
    void  SetYear(int year);
    int GetYear();
   
    void SetAge(int age);
    int GetAge();

    void Print();
};

