#pragma once

class Person
{
private:
    
    int year;
    char f_name[20];
    char s_name[20];
    char profession[20];
    int age;
  

public:
    Person(const char f_name[20], const char s_name[20], const char profession[20], int age, int year);
  
    void SetAge(int age);
    int GetAge();
    void  SetYear( int year);
    int GetYear();
    void SetProfesion (const char profession[20]);
    int GetProfesion();

    void Print();




};