#pragma once
class Employ
{	
	protected:
		char* FirstName;
		char* LastName;
		unsigned int Age;
		int size=20;
		


	public:
		Employ(const char* FirstName, const char* LastName, unsigned int Age);
		~Employ();
		virtual void Print();
		virtual double GetPayment();
		virtual void SAVE();
};

