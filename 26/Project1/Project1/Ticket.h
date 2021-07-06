#pragma once
class Ticket
{

protected:
	int i1, i2, i3, i4, i5, i6, count = 0;
	int size = 20;



public:
	Ticket(int i1, int i2, int i3, int i4, int i5, int i6);	
	virtual double Check();
	


};

