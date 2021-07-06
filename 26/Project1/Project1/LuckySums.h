#pragma once
#include "Ticket.h"
class LuckySums : public Ticket
{
	double count3=0;
public:
	LuckySums(int i1, int i2, int i3, int i4, int i5, int i6);
	
	double Check();

};

