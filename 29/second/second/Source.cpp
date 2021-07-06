#include <iostream>
#include <fstream>
#include <string>


using namespace std;
int main()
{
	std::ifstream if_1("out1.txt", std::ios_base::binary);
	std::ifstream if_2("out2.txt", std::ios_base::binary);
	std::ofstream of_c("ACC.txt", std::ios_base::binary);

	of_c << if_1.rdbuf() << if_2.rdbuf();
    if_1.close(); if_2.close(); of_c.close();
	
    
}