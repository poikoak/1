#pragma once
#include "Ticket.h"
class LuckyCriteria
{
	Ticket** Tickets;
	int size;
	size_t maxSize;
	double count1=0;
public:
	LuckyCriteria(int maxSize);
	~LuckyCriteria();
	void Add(Ticket* ticket);	
	double Check();



};

