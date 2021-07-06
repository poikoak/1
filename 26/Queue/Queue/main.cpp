#include "Queue.h"
#include <iostream>
using namespace std;


int main()
{
    Queue pt(3);
 
        pt.Enqueue(1);
        cout << "first element is: " << pt.Peek() << endl;   
        
         pt.Enqueue(22);
         pt.Dequeue();
         cout << "first element is: " << pt.Peek() << endl;
         pt.Enqueue(4);

        
        cout << "Stack size is " << pt.Lenght() << endl;
        pt.Clear();

        cout << "Stack size is " << pt.Lenght() << endl;
    
}