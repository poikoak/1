//#include <iostream>
//#include <fstream>
//#include <string>
//#include <set>
//#include <list>
//#include <algorithm>
//
//using namespace std;
//
//void main() {
//	auto in = ifstream("in.txt");
//	auto out = ofstream("out.txt");
//	list<string> ls;
//	copy(istream_iterator<string>(in), {}, back_inserter(ls));
//	ls.sort();
//	ls.unique();
//	copy(ls.begin(), ls.end(), ostream_iterator<string>(out, " "));
//}


#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
using namespace std;

void main() {
    ifstream slovar1;
    ifstream slovar2;
    ifstream slovar3;
    slovar1.open("in1.txt");
    slovar2.open("in2.txt");
    slovar3.open("in3.txt");



    ofstream out;
    out.open("out.txt");

    //vector<string> lines;
    string word;
    set<string> s;
    while (slovar1 >> word && slovar2 >> word && slovar3 >> word)
    {

        while(word.find_first_of(",.;~!\"?1234567890-'/") !=-1)
        {
            word.replace(word.find_first_of(",.;~!\"?1234567890-'/)("), 1, "");
        
        }
        s.insert(word);       
    }
    while (slovar2 >> word)
    {

        while (word.find_first_of(",.;~!\"?1234567890-'/") != -1)
        {
            word.replace(word.find_first_of(",.;~!\"?1234567890-'/)("), 1, "");

        }
        s.insert(word);
    }
    while (slovar3 >> word)
    {

        while (word.find_first_of(",.;~!\"?1234567890-'/") != -1)
        {
            word.replace(word.find_first_of(",.;~!\"?1234567890-'/)("), 1, "");

        }
        s.insert(word);
    }
    copy(s.begin(), s.end(), ostream_iterator<string>(out, "\n"));
    slovar1.close();
    slovar2.close();
    slovar3.close();
    out.close();
}
