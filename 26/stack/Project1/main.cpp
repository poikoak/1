#include "Stack.h"
#include <iostream>
using namespace std;




int main()
{
    Stack pt(3);
    try {
        pt.Push(1);
        pt.Push(2);

        // pt.Pop();
        // pt.Pop();
        pt.Push(4);
       // pt.Push(4);
       // pt.Push(4);
       
        cout << "Top element is: " << pt.Peek() << endl;
        cout << "Stack size is " << pt.Lenght() << endl;
        pt.Clear();
     
        cout << "Stack size is " << pt.Lenght() << endl;
    }
    catch (const char* ex)
    {
        cout << ex << endl;
    }
 }