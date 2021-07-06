#include <iostream>

using namespace std;

//–екурсивна€ функци€ принимает 2 строки и вы€сн€ет равны ли они.

//int count_chars(const char* string, const char* s, int w = 0, int q = 0)
//{
//	
//	
//		int res1 = 0;
//		if (string[q])
//			res1 = count_chars(string, q + 1);
//
//		int res2 = 0;
//		if (s[w])
//			res2 = count_chars(s, w + 1);
//
//
//		return (s[q] == s[w]) ? 1 : 0;
//	
//
//
//}
int equal( char* string, char* s)
{
	int res = 0;
	if (string == s)
	/*	return  ? count_chars(string + 1, s) + (s == *string) : 0;*/
		return equal(string+1, s+1, w - 1);
	else
	{
		return 0;
	}



}
int main()
{
	
	char string[] = "1";
	char s[] = "1";
	cout << equal(string,s) << endl;
	

}


//int count_chars(const char* string, char s)
//{
//	return *string ? count_chars(string + 1, s) + (s == *string) : 0;
//}
//
//int main()
//{
//
//
//	char string[] = "123qqwe345asd";
//	char s = 'q';
//	cout << count_chars(string, s) << endl;


