#include <iostream>
#include "LuckyCriteria.h"
#include "Ticket.h"
#include "LuckySums.h"
#include "LuckySequense.h"

using namespace std;



int main()
{
	LuckyCriteria* doc = new LuckyCriteria(20);
	doc->Add(new LuckySums(0,0,0,0,0,0));
	doc->Add(new LuckySequense(0, 0, 0, 0, 0, 0));
	
	
	cout << endl;
	cout << endl;
	cout << "Lucky = " << doc->Check() << endl;

	
	delete doc;
}