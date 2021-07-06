#pragma once
class Vector
{
private:

    int v[5];
    int index;
   
public:
    Vector();
    void SetV(int index, int number);
    Vector(int index, int number);
    int GetV(int index);
    
    void Print();

};

