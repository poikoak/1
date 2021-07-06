#include <io.h>
#include<iostream>
#include<string>
#include<fstream>
#include<map>
using namespace std;

//хотел вынести в отдельную функцию все деиствия с сортировкой но не понял как передать в нее c_file.name

void main()
{
	// переменная, хранящая информацию об одном файле
	_finddata_t c_file;

	// адрес списка найденных файлов
	long hFile;

	// найти файлы по маске и вернуть адрес списка найденных файлов и информацию о первом файле
	hFile = _findfirst("g:\\temp\\*.*", &c_file);
	map<string, int> D;
	if (c_file.attrib & _A_SUBDIR) 
	{
		cout << c_file.name << "   " << "<DIR>" << endl;
	}
	else 
	{
		cout << c_file.name << "   " << c_file.size << endl;
		map<string, int>dict;
		for (ifstream stream(c_file.name); stream;)
		{
			string word;
			while (stream && !isalpha(stream.peek()))//peek() это частный случай map() , который возвращает тот же самый 
													 //объект, который получил 
													 //на входе, возможно, с изменённым внутренним состоянием
													 //Функция isalpha проверяет аргумент, 
													 //передаваемый через параметр сharacter, является ли он строчной или прописной буквой алфавита.
				stream.get();                        //принемает поток
			while (stream && isalpha(stream.peek()))
				word.push_back(tolower(stream.get()));//Функция tolower выполняет преобразование прописных букв в строчные
													  //push_back Для добавления элементоd применяется 
													  //функция push_back(), в который передается добавляемый элемент
			if (!word.empty())//пустая ли строка?
				++dict[word];
		
		}
		
		multimap<int, string, greater<int>>result;
		ofstream res("result.txt");
		for (auto& pair : dict)                     //обьявляем pair i dict эквивалентными друг другу
			result.emplace(pair.second, pair.first);//emplace метод с переменным числом аргументов, который позволяет
													//вызвать нужный конструктор у создаваемого элемента.(для инсерта)
		for (auto& pair : result)                   //обьявляем pair i result эквивалентными друг другу
		{
			cout << pair.first << ": " << pair.second << endl;
			 res << pair.first << ": " << pair.second << endl;
			
		}
		
	}
	// цикл для получения информации об остальных найденных файлах
	while (_findnext(hFile, &c_file) == 0)
	{
		if (c_file.attrib & _A_SUBDIR)
		{
			cout << c_file.name << "   " << "<DIR>" << endl;
		}
		else
		{
			cout << c_file.name << "   " << c_file.size << endl;
			map<string, int>dict;
			for (ifstream stream(c_file.name); stream;)
			{
				string word;
				while (stream && !isalpha(stream.peek()))//peek() это частный случай map() , который возвращает тот же самый 
														 //объект, который получил 
														 //на входе, возможно, с изменённым внутренним состоянием
														 //Функция isalpha проверяет аргумент, 
														 //передаваемый через параметр сharacter, является ли он строчной или прописной буквой алфавита.
					stream.get();                        //принемает поток
				while (stream && isalpha(stream.peek()))
					word.push_back(tolower(stream.get()));//Функция tolower выполняет преобразование прописных букв в строчные
														  //push_back Для добавления элементоd применяется 
														  //функция push_back(), в который передается добавляемый элемент
				if (!word.empty())//пустая ли строка?
					++dict[word];
			
			}
			multimap<int, string, greater<int>>result;
			ofstream res("result.txt");
			for (auto& pair : dict)                     //обьявляем pair i dict эквивалентными друг другу
				result.emplace(pair.second, pair.first);//emplace метод с переменным числом аргументов, который позволяет
														//вызвать нужный конструктор у создаваемого элемента.(для инсерта)
			for (auto& pair : result)                   //обьявляем pair i result эквивалентными друг другу
			{
				cout << pair.first << ": " << pair.second << endl;
				res << pair.first << ": " << pair.second << endl;
				
			}
			
		}
	}
	
	// освободить память от списка найденных файлов
	_findclose(hFile);
}





