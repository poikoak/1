#include <iostream>


using namespace std;
//3. Функция принимает строку и меняет все гласные буквы на символ '!'.


void main()
{
	char s[80];
	cout << "Enter string: " << endl;
	cin.getline(s, 80);
	

	// перебор всех букв строки
	for (int i = 0; s[i] != 0; i++)
	{
		if (s[i] == 'a' || s[i] == 'o' || s[i] == 'i' || s[i] == 'e' || s[i] == 'u' || s[i] == 'y'|| 
			s[i] == 'A' || s[i] == 'O' || s[i] == 'I' || s[i] == 'E' || s[i] == 'U' || s[i] == 'Y')
			s[i] = '!';
	}
	cout << "Changed string: " << endl;
	cout << s << endl;
	

}