#pragma once
class Matrix
{
	
private:
	int** a;
	int rows;	
	int col;	
	
public:
	
	int Matrixq();
	~Matrix();
	
	void SetmatrixROW(int rows);
	int GetmatrixROW();
	
	void SetmatrixCOL(int col);
	int GetmatrixCOL();
	void Set_fill_matrix();
	
	void print();
	void operator() (int n, int m);
	void Save(char filename[]);
	void Load(char filename[]);
};

