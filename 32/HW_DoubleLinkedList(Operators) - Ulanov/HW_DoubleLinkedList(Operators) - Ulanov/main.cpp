//1) ��� ����������� ������ �������� ��������� ������ :
//-operator ++, ������� ��������� � ������� �������� '!' (������, �������)
//- operator --, ������� ������� ���� ����� � ����� ������(������, �������)
//- operator >>, << ������� �� ����� � � ����(������ ������)
//
//fstream stream;
//stream << my_list;
//stream.close();

#pragma warning(disable : 4996)
#include <iostream>
#include "DoubleLinkedList.h"

void main() 
{
	DoubleLinkedList lst;
	lst.Add("One");
	lst.Add("Two");
	lst.Add("Three");
	lst.Add("One");
	lst.Print();

	//std::cout << "Count of \"One\": " << lst.Get_Count("One") << std::endl;

	DoubleLinkedList third;
	third.Add("One");
	third.Add("Two");
	third.Add("Three");
	third.Print();
	--lst;
	std::cout << lst;

	//system("test.txt");
	/*DoubleLinkedList second = third;
	std::cout << "Second print: \n";
	second.Print();*/
	std::ofstream result;
	result.open("result.txt");
	if (!result.fail())
	{
		result << lst;
		result.close();
	}
	//stream << my_list;
	//stream.close();
	
}