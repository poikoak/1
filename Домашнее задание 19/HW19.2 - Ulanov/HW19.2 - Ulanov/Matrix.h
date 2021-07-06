#pragma once
class Matrix
{
	int** m;
	int rows;
	int columns;
	void FillMatrix(); //���������� ������� ���������������� �������
public:
	Matrix(); //����������� ��� ����������
	Matrix(int rows, int columns); //����������� � ����������� ����� � ��������
	~Matrix(); //����������

	int& operator() (int x, int y);

	void Save(char filename[], int rows, int columns);
	void Load(char filename[], int rows, int columns);
	void Print();

	Matrix(const Matrix& source); // ����������� �����������
	Matrix& operator = (const Matrix& source); // �������� ������������
	bool operator == (Matrix& source); // �������� �����
	bool operator != (Matrix& source); // �������� �� �����
	Matrix& operator+(int n); // �������� �������� ����� n � ������� ��������
	Matrix& operator+(Matrix& source); // �������� �������� ������
};