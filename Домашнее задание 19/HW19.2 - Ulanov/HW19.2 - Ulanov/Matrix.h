#pragma once
class Matrix
{
	int** m;
	int rows;
	int columns;
	void FillMatrix(); //Заполнение матрицы псевдослучайными числами
public:
	Matrix(); //Конструктор без параметров
	Matrix(int rows, int columns); //Конструктор с параметрами строк и столбцов
	~Matrix(); //Деструктор

	int& operator() (int x, int y);

	void Save(char filename[], int rows, int columns);
	void Load(char filename[], int rows, int columns);
	void Print();

	Matrix(const Matrix& source); // Конструктор копирования
	Matrix& operator = (const Matrix& source); // Оператор присваивания
	bool operator == (Matrix& source); // Оператор равно
	bool operator != (Matrix& source); // Оператор не равно
	Matrix& operator+(int n); // Оператор сложения числа n к каждому элементу
	Matrix& operator+(Matrix& source); // Оператор сложения матриц
};