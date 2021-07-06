#include<iostream>

using namespace std;

//Пользователь вводит двумерный динамический массив,
//программа находит сумму нечётных отрицательных элементов

int getSumNegOdd(int** arr, int row, int col, int n = 1, int i = 0, int j = -1) {

	int res = 0;

	if (j < col - 1)
		++j;
	else if (i < row - 1){
		++i;
		j = 0;
	}	

	if (n < (row * col)) {		
		
		res = getSumNegOdd(arr, row, col, ++n, i, j);
	}		

	return res + ((arr[i][j] < 0 && arr[i][j] % 2 == -1) ? arr[i][j] : 0);
}

void main() {

	int row_size, col_size;

	cout << "Enter size row: ";
	cin >> row_size;
	cout << "Enter size column: ";
	cin >> col_size;

	int** matrix = new int*[row_size];
	for (int i = 0; i < row_size; i++){
		matrix[i] = new int[col_size];
	}

	for (int i = 0; i < row_size; i++)	{
		for (int j = 0; j < col_size; j++) {
			cout << "Enter your number: ";
			cin >> matrix[i][j];
		}
	}

	cout << "\nSum negative numbers: " << getSumNegOdd(matrix, row_size, col_size) << endl;	

	for (int i = 0; i < row_size; i++) {
		delete[] matrix[i];
	}

	delete[] matrix;

}