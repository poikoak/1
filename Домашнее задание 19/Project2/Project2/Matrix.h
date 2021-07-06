#pragma once
class Matrix
{
	
	
	int** a;
	int rows;	
	int col;	
	void Set_fill_matrix();


public:
	Matrix();
	Matrix(int rows, int col);

	~Matrix();
	
	Matrix(const Matrix& s);
	Matrix& operator = (const Matrix& s); 
	bool operator == (Matrix& s); 
	bool operator != (Matrix& s); 
	Matrix& operator+(int n); 
	Matrix& operator+(Matrix& s); 
	
	void print();
	
};

