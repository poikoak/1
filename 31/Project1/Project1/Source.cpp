#include <io.h>
#include<iostream>
#include<string>
#include<fstream>
#include<map>
using namespace std;

//����� ������� � ��������� ������� ��� �������� � ����������� �� �� ����� ��� �������� � ��� c_file.name

void main()
{
	// ����������, �������� ���������� �� ����� �����
	_finddata_t c_file;

	// ����� ������ ��������� ������
	long hFile;

	// ����� ����� �� ����� � ������� ����� ������ ��������� ������ � ���������� � ������ �����
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
			while (stream && !isalpha(stream.peek()))//peek() ��� ������� ������ map() , ������� ���������� ��� �� ����� 
													 //������, ������� ������� 
													 //�� �����, ��������, � ��������� ���������� ����������
													 //������� isalpha ��������� ��������, 
													 //������������ ����� �������� �haracter, �������� �� �� �������� ��� ��������� ������ ��������.
				stream.get();                        //��������� �����
			while (stream && isalpha(stream.peek()))
				word.push_back(tolower(stream.get()));//������� tolower ��������� �������������� ��������� ���� � ��������
													  //push_back ��� ���������� ��������d ����������� 
													  //������� push_back(), � ������� ���������� ����������� �������
			if (!word.empty())//������ �� ������?
				++dict[word];
		
		}
		
		multimap<int, string, greater<int>>result;
		ofstream res("result.txt");
		for (auto& pair : dict)                     //��������� pair i dict �������������� ���� �����
			result.emplace(pair.second, pair.first);//emplace ����� � ���������� ������ ����������, ������� ���������
													//������� ������ ����������� � ������������ ��������.(��� �������)
		for (auto& pair : result)                   //��������� pair i result �������������� ���� �����
		{
			cout << pair.first << ": " << pair.second << endl;
			 res << pair.first << ": " << pair.second << endl;
			
		}
		
	}
	// ���� ��� ��������� ���������� �� ��������� ��������� ������
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
				while (stream && !isalpha(stream.peek()))//peek() ��� ������� ������ map() , ������� ���������� ��� �� ����� 
														 //������, ������� ������� 
														 //�� �����, ��������, � ��������� ���������� ����������
														 //������� isalpha ��������� ��������, 
														 //������������ ����� �������� �haracter, �������� �� �� �������� ��� ��������� ������ ��������.
					stream.get();                        //��������� �����
				while (stream && isalpha(stream.peek()))
					word.push_back(tolower(stream.get()));//������� tolower ��������� �������������� ��������� ���� � ��������
														  //push_back ��� ���������� ��������d ����������� 
														  //������� push_back(), � ������� ���������� ����������� �������
				if (!word.empty())//������ �� ������?
					++dict[word];
			
			}
			multimap<int, string, greater<int>>result;
			ofstream res("result.txt");
			for (auto& pair : dict)                     //��������� pair i dict �������������� ���� �����
				result.emplace(pair.second, pair.first);//emplace ����� � ���������� ������ ����������, ������� ���������
														//������� ������ ����������� � ������������ ��������.(��� �������)
			for (auto& pair : result)                   //��������� pair i result �������������� ���� �����
			{
				cout << pair.first << ": " << pair.second << endl;
				res << pair.first << ": " << pair.second << endl;
				
			}
			
		}
	}
	
	// ���������� ������ �� ������ ��������� ������
	_findclose(hFile);
}





