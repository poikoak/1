#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;

const int ArraySize = 20;
 int countBubble1;
 int countBubble2;
 int countBubbleMAX;

 int countSelection1;
 int countSelection2;
 int countSelectionMAX;

 int countInsert1;
 int countInsert2;
 int countInsertMAX;

 int countQ1;
 int countQ2;
 int countQMAX;

 int countgnome1;
 int countgnome2;
 int countgnomeMAX;

void PrintArray(int* arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

/// <summary>
/// сортировка методом "пузырька"
/// </summary>
/// <param name="array"></param>
/// <param name="size"></param>
void BubbleSort(int* array, int size)
{
	countBubble1=0;
	 countBubble2=0;
	 countBubbleMAX=0;
	 
	// перебор всех элементов массива
	for (int i = 1; i < size; i++)
	{
		
		// проход массива от конца в начало со "всплыванием" одного элемента
		for (int j = size - 1; j >= i; j--)
		{
			countBubble1 += 1;
			if (array[j - 1] > array[j])
			{
				// перестановка элементов
				int temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
				countBubble2++;
			}
		}
		
	
	}
	
	countBubbleMAX = countBubble1 + countBubble2;

}

/// <summary>
/// сортировка выбором
/// </summary>
/// <param name="arr">сортируемый массив</param>
/// <param name="size">размер массива</param>
void SelectionSort(int* arr, long size) 
{
	long i, j, k;
	int x;
	countSelection1=0;
	 countSelection2=0;
	 countSelectionMAX=0;
	// i - номер текущего шага
	for (i = 0; i < size; i++) 
	{   	
		k = i; 
		x = arr[i];

		// цикл выбора наименьшего элемента
		for (j = i + 1; j < size; j++)
		{
			countSelection1 += 1;
			if (arr[j] < x)
			{
				// k - индекс наименьшего элемента
				k = j;
				x = arr[j];
				
				
			}
		}
		countSelection1 += 1;
		if (arr[k] != arr[i])
		{
			// поменять местами наименьший элемент с a[i]
			arr[k] = arr[i];
			arr[i] = x;
			countSelection2 += 1;
			cout << "number of permutations = " << countSelection2 << endl;
		}
		
	}
	
	countSelectionMAX = countSelection1 + countSelection2;
}

/// <summary>
/// сортировка вставками
/// </summary>
/// <param name="array">сортируемый массив</param>
/// <param name="size">размер массива</param>
void InsertionSort(int* array, int size)
{
	int i, j, k, temp;
	countInsert1=0;
	countInsert2=0;
	countInsertMAX=0;
	// цикл по всем элементам массива
	for (i = 1; i < size; i++)
	{
		
		// текущий элемент, для которого подыскивается позиция
		temp = array[i];

		// поиск правильной позиции (j - искомый индекс - результат работы цикла)
		for (j = 0; j < i; j++)
			if (array[j] > temp) break;
		countInsert1 += 1;
		// если элемент стоит на своём месте - продолжить
		if (j == i) continue;

		// смещение элементов слева-направо
		for (k = i; k > j; k--)
			array[k] = array[k - 1], countInsert2++;

		// поставить элемент в правильную позицию
		array[j] = temp;

		
		
	}
	countInsertMAX = countInsert1 + countInsert2;
}

/// <summary>
/// рекурсивная функция быстрой сортировки
/// </summary>
/// <param name="array">сортируемый массив</param>
/// <param name="start">индекс начала сортировки</param>
/// <param name="end">индекс конца сортировки</param>
void QSort(int* array, int start, int end)
{

	 countQ1=0;
	 countQ2=0;
	 countQMAX=0;
	
	// в случае неправильных данных - выйти
	if (start >= end) return;
	int i = start, j = end;

	// выбрать середину массива
	int baseElementIndex = start + (end - start) / 2;

	// пока индекс левой части меньше индекса правой части
	while (i < j)
	{
		// значение пограничного элемента
		int value = array[baseElementIndex];

		// перемещать индекс левой части массива вперёд, пока не встретится слишком большой элемент
		while (i < baseElementIndex && (array[i] <= value))
		{
			
			i++;
		}
		
		// перемещать индекс правой части массива назад, пока не встретится слишком маленький элемент
		while (j > baseElementIndex && (array[j] >= value))
		{
			
			j--;
		}
	
		// i, j - индексы элементов, которые нужно поменять местами
		// если индесы правильные (есть смысл обмена элементов)
		if (i < j)
		{
			// обменять элемент с левой стороны на элемент с правой стороны
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			countQ2++;
			//PrintArray(array, ArraySize);

			// корректировка базового элемента
			if (i == baseElementIndex) baseElementIndex = j;
			else if (j == baseElementIndex) baseElementIndex = i;
		}
	
	}

	// рекурсивная сортировка левой и правой частей массива
	if (true)
	{
		QSort(array, start, baseElementIndex);
		countQ1++;
		QSort(array, baseElementIndex + 1, end);
		countQ1++;
	}
	countQMAX = countQ1 + countQ2;
}


void QuickSort(int* arr, int size)
{
	QSort(arr, 0, size - 1);
}



void gnomeSort(int arr[], int n)
{
	int index = 0;
	countgnome1=0;
	countgnome2=0;
    countgnomeMAX=0;
	while (index < n) 
	{
		countgnome1++;
	
		if (index == 0)
			index++;
		if (arr[index] >= arr[index - 1])
		{
			index++;
			countgnome2++;
			
		}
		else {
			swap(arr[index], arr[index - 1]);
			index--;
			countgnome2++;
			
		}
	}
	
	countgnomeMAX = countgnome1 + countgnome2;
}



int main()
{
	srand(time(0));
	int MAX = 0, MIN = 0;
	int arr[ArraySize];

	for (size_t i = 0; i < ArraySize; i++)
	{
		arr[i] = rand() % 10;
	}

	

	BubbleSort(arr, ArraySize);
	
	SelectionSort(arr, ArraySize);
	
	InsertionSort(arr, ArraySize);

	QuickSort(arr, ArraySize);

	gnomeSort(arr, ArraySize);



	/*MIN = countBubbleMAX;   MAX = countBubbleMAX;
	if (countSelectionMAX < MIN)
		MIN = countSelectionMAX;*/
	/*if (countInsertMAX < MIN)
		MIN = countInsertMAX;*/
	/*if (countQMAX < MIN)
		MIN = countQMAX;
	if (countgnomeMAX < MIN)
		MIN = countgnomeMAX;

	if (countSelectionMAX > MAX)
		MAX = countSelectionMAX;
	if (countInsertMAX > MAX)
		MAX = countInsertMAX;
	if (countQMAX > MAX)
		MAX = countQMAX;
	if (countgnomeMAX > MAX)
		MAX = countgnomeMAX;
	cout << MIN << " - Fastest algorithm \n" << MAX << " - Slowest algorithm";*/
	
	cout << countBubbleMAX << " - actions in the algorithm Bubble\n";
	cout << countSelectionMAX << " - actions in the algorithm Selection\n ";
	cout << countInsertMAX << " - actions in the algorithm Insert\n ";
	cout << countgnomeMAX << " - actions in the algorithm gnome\n";
	cout << countQMAX << " - actions in the algorithm  Quick\n";
	cout << "____________________________________________________________\n";
	//cout << "max(1,2)==" << max(countBubbleMAX, countSelectionMAX) << endl;

	if (countBubbleMAX < countSelectionMAX && countBubbleMAX < countInsertMAX
		&& countBubbleMAX < countQMAX
		&& countBubbleMAX < countgnomeMAX)	
		cout << countBubbleMAX << " - Fastest algorithm Bubble";

		else if
			(countSelectionMAX < countBubbleMAX && countSelectionMAX < countInsertMAX
				&& countSelectionMAX < countQMAX
				&& countSelectionMAX < countgnomeMAX)		
			cout << countSelectionMAX << " - Fastest algorithm Selection ";

			else if (countInsertMAX < countBubbleMAX && countInsertMAX < countSelectionMAX
				&& countInsertMAX < countQMAX
				&& countInsertMAX < countgnomeMAX)			
				cout << countInsertMAX << " - Fastest algorithm Insert ";

				else if (countQMAX < countBubbleMAX && countQMAX < countInsertMAX
					&& countQMAX < countSelectionMAX
					&& countQMAX < countgnomeMAX)				
					cout << countQMAX << " - Fastest algorithm  Quick";


				else if (countgnomeMAX < countBubbleMAX&& countgnomeMAX < countSelectionMAX
					&& countgnomeMAX < countQMAX
					&& countgnomeMAX < countInsertMAX)				
					cout << countgnomeMAX << " - Fastest algorithm gnome";
				
				
			
		
	
}
