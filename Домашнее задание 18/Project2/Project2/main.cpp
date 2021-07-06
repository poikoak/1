#include <iostream>
#include "Matrix.h"
using namespace std;
void main()
{

	Matrix Matrix;
	
	Matrix.SetmatrixROW(3);
	
	Matrix.SetmatrixCOL(3);
	Matrix.Matrixq();
	Matrix.Set_fill_matrix();
	Matrix.print();
	cout << "_________________" << endl;
	Matrix.operator() (4, 9);
	Matrix.print();
	cout << "_________________" << endl;
	char destFilename[200];
	cout << "Enter name of destination file: ";
	cin.getline(destFilename, 200);
	Matrix.Save(destFilename);
	Matrix.Load(destFilename);


}