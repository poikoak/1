#pragma once
#include "Employ.h"
class SalesPerson : public Employ
{
	
	int Price=500;//цена продукта
	int sold;//сколько продал товара
	int payment;//итоговая зп
	int p;//переменная чтоб найти общ сумму продаж


public:
	SalesPerson(const char* FirstName, const char* LastName, unsigned int Age, int sold);
	void Print();
	double GetPayment();
	void SAVE();
};

