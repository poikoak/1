#include "LuckyCriteria.h"
#include <iostream>
#include <fstream>
using namespace std;

LuckyCriteria::LuckyCriteria(int maxSize)
{
	this->maxSize = maxSize;
	size = 0;
	Tickets = new Ticket * [maxSize];
}

LuckyCriteria::~LuckyCriteria()
{
	for (size_t i = 0; i < size; i++)
	{
		delete Tickets[i];
	}

	delete[] Tickets;
}

void LuckyCriteria::Add(Ticket* ticket)
{
	if (size < maxSize)
		Tickets[size++] = ticket;
}


double LuckyCriteria::Check()
{
	
	float count = 0;

	for (size_t i = 0; i < size; i++)
	{

		count += Tickets[i]->Check();
	}

	return count;
}

