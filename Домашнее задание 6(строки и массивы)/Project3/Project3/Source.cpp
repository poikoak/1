#include <iostream>
#include <conio.h>


using namespace std;


int Vowels_cout(const char s[])
	//3. Функция принимает строку и подсчитывает количество гласных букв в ней	
{
	int vowels_count = 0;
	for (size_t i = 0; s[i] != 0; i++)
	{
		if (s[i] == 'a' || s[i] == 'o' || s[i] == 'i' || s[i] == 'e' || s[i] == 'u' || s[i] == 'y')
			vowels_count++;
	}
	return vowels_count;
}
void main()
{
	char s[80];
	cout << "Enter string: ";
	cin.getline(s, 80);
	cout << "String contains vowels letters : " << Vowels_cout(s)<< endl;
}