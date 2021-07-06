#include <iostream>
#include <string>
#include <cstdlib>
#include <iterator>
#include <unordered_set>  
/*Плюсы:
Быстрее(promises амортизируется O(1) для поиска)
Легко конвертировать базовые примитивы в потокобезопасные, по сравнению с tree - DS
Минусы :
Поиск не гарантируется O(1) Тройной худший случай - O(n)
Не такой компактный, как дерево. (для практических целей коэффициенты нагрузки никогда не 1)*/
#include <fstream>
#include <regex>//регулярные выражения
using namespace std;

int main()
{

    ifstream ifs{ "in.txt" }; // файл
    if (ifs.is_open())
    {
        unordered_set<string> sst; // множество для хранения найденных слов
        regex rgx{ "[А-Яа-яЁё\\d[:alpha:]]+" }; // маска для поиска слов
        string str{ istreambuf_iterator<char>{ifs.rdbuf()}, {} }, sres; // чтение всего файла в string
        ifs.close();
        ssub_match suf; //исключить из поиска
        for (sregex_iterator ib{ str.begin(), str.end(), rgx }, ie; ib != ie; ++ib) // цикл поиска слов по маске
        {
            sres += ib->prefix(); // копируем префикс найденного слова в выходную строку
            if (sst.insert(ib->str()).second) // если слово отсутствует в множестве то копируем слово в выходную строку
            {
                sres += ib->str();
            }
            suf = ib->suffix(); // запоминаем суффикс слова
        }
        sres += suf; // копируем суффикс в выходную строку
        cout << sres << std::endl; // вывод результата
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
