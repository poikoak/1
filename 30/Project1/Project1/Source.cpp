#include <iostream>
#include <string>
#include <cstdlib>
#include <iterator>
#include <unordered_set>  
/*�����:
�������(promises �������������� O(1) ��� ������)
����� �������������� ������� ��������� � ����������������, �� ��������� � tree - DS
������ :
����� �� ������������� O(1) ������� ������ ������ - O(n)
�� ����� ����������, ��� ������. (��� ������������ ����� ������������ �������� ������� �� 1)*/
#include <fstream>
#include <regex>//���������� ���������
using namespace std;

int main()
{

    ifstream ifs{ "in.txt" }; // ����
    if (ifs.is_open())
    {
        unordered_set<string> sst; // ��������� ��� �������� ��������� ����
        regex rgx{ "[�-��-���\\d[:alpha:]]+" }; // ����� ��� ������ ����
        string str{ istreambuf_iterator<char>{ifs.rdbuf()}, {} }, sres; // ������ ����� ����� � string
        ifs.close();
        ssub_match suf; //��������� �� ������
        for (sregex_iterator ib{ str.begin(), str.end(), rgx }, ie; ib != ie; ++ib) // ���� ������ ���� �� �����
        {
            sres += ib->prefix(); // �������� ������� ���������� ����� � �������� ������
            if (sst.insert(ib->str()).second) // ���� ����� ����������� � ��������� �� �������� ����� � �������� ������
            {
                sres += ib->str();
            }
            suf = ib->suffix(); // ���������� ������� �����
        }
        sres += suf; // �������� ������� � �������� ������
        cout << sres << std::endl; // ����� ����������
        ofstream out;
        unordered_set<string> s;
        out.open("out.txt");
        s.insert(sres);
        copy(s.begin(), s.end(), ostream_iterator<string>(out, "\n"));
        out.close();
    }
    else
    {
        cerr << "Unable to open file\n";
    }
}
