#include <iostream>
#include <conio.h>


using namespace std;
//4. ‘ункци€ принимает строку и провер€ет, 
//€вл€етс€ ли эта строка положительным целым числом (например: "2673")

int Check(const char a[], int size)
{
    
    if (a == 0)  return false;
    for (size_t i = 0; i < size; i++)
    {
         if (a[i] >= '0' && a[i] <= '9') 
             return true;
         else 
         {
             return false; 
         }                  
         
    }
    
}

void main()
{
    char a[80];
    cout << "Enter string: ";
    cin.getline(a, 80);  

     cout << "Entered number is ";

    if (Check(a, 80))
        cout << "integer" << endl;
    else
        cout << "NOT integer" << endl;
    
}