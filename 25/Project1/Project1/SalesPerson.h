#pragma once
#include "Employ.h"
class SalesPerson : public Employ
{
	
	int Price=500;//���� ��������
	int sold;//������� ������ ������
	int payment;//�������� ��
	int p;//���������� ���� ����� ��� ����� ������


public:
	SalesPerson(const char* FirstName, const char* LastName, unsigned int Age, int sold);
	void Print();
	double GetPayment();
	void SAVE();
};

