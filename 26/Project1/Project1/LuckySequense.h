#pragma once
#include "Ticket.h"
class LuckySequense : public Ticket
{
	double count2=0;
public:
	LuckySequense(int i1, int i2, int i3, int i4, int i5, int i6);

	double Check();
	
};