#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>




#include <chrono>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>



using namespace std;
typedef map<string, int> Str_Map;


void map_()
{

    auto begin = chrono::steady_clock::now();
    ifstream slovar;
    slovar.open("eng.txt");
    Str_Map w;   
    string words;
    while (slovar >> words)
    {
           auto it = remove_if(words.begin(), words.end(), [](char c) { return ispunct(c); });
            words.erase(it, words.end());
            auto it_2 = remove_if(words.begin(), words.end(), [](char c) { return isdigit(c); });
            words.erase(it_2, words.end());
        ++w[words];

    }
    for (Str_Map::iterator p = w.begin(); p != w.end(); ++p)
    {
        // cout << p->first << " occurred " << p->second << " times.\n";

    }
    auto end = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(end - begin);
    cout << "Run time map: " << elapsed_ms.count() << " ms\n";
    ofstream out;
    out.open("map.txt");
    for (auto& pair : w)
    {
        out << pair.first << ": " << pair.second << '\n';
    }
    slovar.close();
    out.close();

}
void un_map()
{

    auto begin = chrono::steady_clock::now();
    ifstream slovar2;
    slovar2.open("eng.txt");
    unordered_map<string, unsigned> m;
    string word;
    while (slovar2 >> word)
    {
        auto it = remove_if(word.begin(), word.end(), [](char c) { return ispunct(c); });
        word.erase(it, word.end());
        auto it_2 = remove_if(word.begin(), word.end(), [](char c) { return isdigit(c); });
        word.erase(it_2, word.end());
        ++m[word]; // increment the count for this word
    }
    for (auto const& p : m)
    {
        //cout << p.first << ':' << p.second << '\n';
    }
    auto end = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(end - begin);
    cout << "Run time unordered_map: " << elapsed_ms.count() << " ms\n";
    ofstream out;
    out.open("unordered_map.txt");
    for (auto& pair : m)
    {
        out << pair.first << ": " << pair.second << '\n';
    }
    slovar2.close();
    out.close();


}

void vector_()
{
    vector<string> words;
    vector<uint64_t> counters;
    words.reserve(128);
    counters.reserve(128);
    auto begin = chrono::steady_clock::now();
    ifstream slovar;
    slovar.open("eng.txt");
    
    for (string word; slovar >> word;)
    {
        auto it = remove_if(word.begin(), word.end(), [](char c) { return ispunct(c); });
        word.erase(it, word.end());
        auto it_2 = remove_if(word.begin(), word.end(), [](char c) { return isdigit(c); });
        word.erase(it_2, word.end());
        size_t index = 0;
        while (index != words.size() && word != words[index])
            ++index;

        if (index != words.size()) // слово есть в words,
        {
            counters[index]++;
        }
        else // слова нет в words -- добавим его.
        {
            words.push_back(word);
            counters.push_back(1);
            
        }
       
    }

    auto end = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(end - begin);
    cout << "Run time VECTOR: " << elapsed_ms.count() << " ms\n";
    ofstream out;
    out.open("VECTOR.txt");
    vector<pair<string, int>>m;
    for (size_t i = 0; i < words.size(); ++i)
    m.push_back(pair <string, int>(words[i], counters[i]));
    for (auto& pair : m)
    {
        out << pair.first << ": " << pair.second << '\n';
    } 
    out.close();
    slovar.close();
}

void list_()
{
   
    list <pair<string, size_t>> m;   
    string word;
    auto begin = chrono::steady_clock::now();
    ifstream slovar;
    slovar.open("eng.txt");          
    while (slovar >> word)
    {      
        auto it = remove_if(word.begin(), word.end(), [](char c) { return ispunct(c); });
        word.erase(it, word.end());       
        auto it_2 = remove_if(word.begin(), word.end(), [](char c) { return isdigit(c); });
        word.erase(it_2, word.end());       
        list<pair<string, size_t>>::iterator pos;
        for (pos = m.begin(); pos != m.end(); pos++)
        {
            if (pos->first == word)
            {              
                pos->second++;
                break;
            }
        }
      
            m.push_back(pair <string, size_t>(word, 1));
    }
            auto end = chrono::steady_clock::now();
            auto elapsed_ms = chrono::duration_cast<chrono::seconds>(end - begin);
            cout << "Run time list: " << elapsed_ms.count() << " seconds\n";
           
            ofstream out;
            out.open("list.txt");
            for (const auto& pair : m)
            {
                out << pair.second << ": " << pair.first << "\n";
            }
            slovar.close();
            out.close();
}
int main()
{
    map_(); 
    un_map();
    vector_();
    list_();

}   