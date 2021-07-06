#pragma once
#include <unordered_map>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <time.h>
using namespace std;

template <class T> class Link;
template <class T> class Graph;

template <class T>
class Vertex
{
	friend class Graph<T>;
	friend class Link<T>;

	// название вершины
	string title;

	// номер вершины
	unsigned int id;

	// вес вершины графа
	int weight;

	// рёбра, подходящие к данной вершине
	list<Link<T>*> links;

	// удаление ребра ТОЛЬКО у данной вершины
	bool RemoveLink(unsigned int linkId);

	// метка вершины, нужна для работы алгоритмов поиска
	int label;
public:
	Vertex(unsigned int id, const string title, int weight);
	~Vertex();

	// получить название вершины
	string GetTitle();

	// получить ключ вершины
	unsigned int GetId();

	// возвращает количество входящих рёбер
	unsigned int GetLinksCount();

	void Print();
};
template <class T>
Vertex<T>::Vertex(unsigned int id, const string _title, int weight)
{
	this->id = id;
	this->weight = weight;
	this->title = _title;
}
template <class T>
Vertex<T>::~Vertex()
{
	// перебор всех рёбер входящих в удаляемую вершину
	list<Link<T>*>::iterator pos = links.begin();
	while (pos != links.end())
	{
		// указатель на текущее ребро
		Link<T>* currentLink = *(pos);

		pos++;

		// удаление текущего ребра
		delete currentLink;
	}

	// очистить список всех рёбер вершины
	//links.clear();
}

// удаление рёбра по Id у вершины без удаления их в соседней вершине
template <class T>
bool Vertex<T>::RemoveLink(unsigned int linkId)
{
	list<Link<T>*>::iterator pos;
	for (pos = links.begin(); pos != links.end(); pos++)
	{
		if ((*pos)->id == linkId)
		{
			links.erase(pos);
			return true;
		}
	}

	return false;
}

// вернуть количество рёбер, входящих в вершину
template <class T>
unsigned int Vertex<T>::GetLinksCount()
{
	return links.size();
}

// возвратить Id вершины
template <class T>
unsigned int Vertex<T>::GetId()
{
	return this->id;
}
template <class T>
string Vertex<T>::GetTitle()
{
	return title;
}
template <class T>
void Vertex<T>::Print()
{
	cout << "VERTEX: " << title << endl;

	// перебрать все входящие рёбра и вызвать у них метод Print
	list<Link<T>*>::iterator pos;
	for (pos = links.begin(); pos != links.end(); pos++)
	{
		(*pos)->Print();
	}
	cout << endl;
}
template <class T>
class Link
{
	friend class Graph<T>;
	friend class Vertex<T>;

	// указатель на вершину, из которой идёт ребро
	Vertex<T>* from;

	// указатель на вершину, в которую идёт ребро
	Vertex<T>* to;

	// название ребра
	string title;

	// номер ребра
	unsigned int id;

	// вес ребра графа
	int weight;
public:
	Link(unsigned int id, const string title, int weight, Vertex<T>* from, Vertex<T>* to);
	~Link();

	// получить номер ребра
	unsigned int GetId();

	// получить название ребра
	string GetTitle();
	void Print();
};
template <class T>
Link<T>::Link(unsigned int id, const string _title, int weight, Vertex<T>* from, Vertex<T>* to)
{
	this->id = id;
	this->weight = weight;
	this->from = from;
	this->to = to;
	this->title = _title;
}
template <class T>
Link<T>::~Link()
{
	// удалить указатели на удаляемое ребро в смежных вершинах
	from->RemoveLink(id);
	to->RemoveLink(id);
}

// возвратить Id ребра
template <class T>
unsigned int Link<T>::GetId()
{
	return this->id;
}
template <class T>
string Link<T>::GetTitle()
{
	return title;
}
template <class T>
void Link<T>::Print()
{
	cout << "LINK: " << title << ", From: " << from->GetTitle() << ", To: " << to->GetTitle() << endl;
}
template <class T>
class Graph
{
	// название графа
	T title;

	// номер следующей вершины, которая будет создана
	unsigned int vertexId = 0;

	// количество вершин графа
	unsigned int vertexCount = 0;

	// номер следующего ребра, который будет создан
	unsigned int linkId = 0;

	// количество рёбер графа
	unsigned int linkCount = 0;

	// указатель на список вершин графа
	unordered_map<T, Vertex<T>*>* vertices;

public:

	// Результирующий список названий вершин - ответ алгоритмов поиска
	list<Vertex<T>*> FoundVertices;

	Graph(const T title);
	~Graph();

	// находит вершину в списке вершин по её названию
	Vertex<T>* FindVertex(const T title);

	// добавление вершины в граф
	unsigned int AddVertex(const T title, unsigned int weight);

	// добавление ребра, соединяющего две вершины
	unsigned int AddLink(const T from, const T to, const T title, unsigned int weight);

	// удаление вершины по Id
	bool RemoveVertex(unsigned int vertexId);

	// удаление вершины по названию
	bool RemoveVertex(const T title);

	// волновой алгоритм для невзвешенного графа
	void GetRoute(T from, T to);

	// печать результата поиска
	void PrintFoundPath();

	void Print();


};
template <class T>
Graph<T>::Graph(const T _title)
{
	this->title = _title;

	// выделение памяти под список вершин
	vertices = new unordered_map<T, Vertex<T>*>();
}
template <class T>
Graph<T>::~Graph()
{
	// перебор списка вершин и удаление каждой вершины
	unordered_map<T, Vertex<T>*>::iterator pos = vertices->begin();
	while (pos != vertices->end())
	{
		// указатель на текущую вершину
		Vertex<T>* currentVertex = pos->second;

		// переместить указатель на следующую вершину
		pos++;

		// удалить текущую вершину
		delete currentVertex;
	}

	// удаление списка вершин графа
	delete vertices;
}

// поиск вершины по названию
template <class T>
Vertex<T>* Graph<T>::FindVertex(const T title)
{
	unordered_map<T, Vertex<T>*>::iterator pos = vertices->find(title);
	if (pos != vertices->end())
		return pos->second;

	return nullptr;
}

// добавление вершины в граф
template <class T>
unsigned int Graph<T>::AddVertex(const T title, unsigned int weight)
{
	if (FindVertex(title) == 0)
	{
		Vertex<T>* vertex = new Vertex<T>(vertexId++, title, weight);
		if (vertex != nullptr)
		{
			// добавление вершины в список вершин
			vertices->insert(make_pair(title, vertex));

			// увеличить количество вершин на 1
			vertexCount++;

			// возвратить Id созданной вершины
			return vertexId - 1;
		}
	}
	return -1;
}
template <class T>
unsigned int Graph<T>::AddLink(const T from, const T to, const T title, unsigned int weight)
{
	// получить указатели на вершины по их названиям
	Vertex<T>* vertexFrom = FindVertex(from);
	Vertex<T>* vertexTo = FindVertex(to);

	if (vertexFrom != nullptr && vertexTo != nullptr)
	{
		// создание объекта ребра
		Link<T>* link = new Link(linkId++, title, weight, vertexFrom, vertexTo);
		if (link != nullptr)
		{
			// добавление указателей на созданное ребро в списки рёбер каждой из соединяемых вершин
			vertexFrom->links.push_back(link);
			vertexTo->links.push_back(link);

			// увеличить количество рёбер на 1
			linkCount++;

			// возвратить Id созданного ребра
			return linkId - 1;
		}
	}

	return -1;
}

// удаление вершины по Id
template <class T>
bool Graph<T>::RemoveVertex(unsigned int vertexId)
{
	// перебор списка вершин
	unordered_map<T, Vertex<T>*>::iterator pos;
	for (pos = vertices->begin(); pos != vertices->end(); pos++)
	{
		Vertex<T>* currentVertex = pos->second;

		// если найдена нужная вершина
		if (currentVertex->id == vertexId)
		{
			// из общего количества рёбер графа вычесть количество рёбер, подходящее к удаляемой вершине
			linkCount -= currentVertex->GetLinksCount();

			// уменьшить количество вершин на 1
			vertexCount--;

			// удаление вершины
			delete currentVertex;

			vertices->erase(pos);

			return true;
		}
	}

	return false;
}

// удаление вершины по названию
template <class T>
bool Graph<T>::RemoveVertex(const T title)
{
	unordered_map<T, Vertex<T>*>::iterator pos;
	for (pos = vertices->begin(); pos != vertices->end(); pos++)
	{
		Vertex<T>* currentVertex = pos->second;

		if (currentVertex->title == title)
		{
			linkCount -= currentVertex->GetLinksCount();
			vertexCount--;

			vertices->erase(pos);

			delete currentVertex;

			return true;
		}
	}

	return false;
}
template <class T>
void Graph<T>::Print()
{
	cout << "GRAPH: " << title << endl;
	cout << "Vertices: " << vertexCount << " Links: " << linkCount << endl << endl;

	// перебрать список вершин и напечатать все вершины
	unordered_map<T, Vertex<T>*>::iterator pos;
	for (pos = vertices->begin(); pos != vertices->end(); pos++)
	{
		pos->second->Print();
	}
}

// волновой алгоритм для невзвешенного графа
template <class T>
void Graph<T>::GetRoute(T from, T to)
{

	// очистить предыдущий результат
	FoundVertices.clear();

	// Список текущих просмотренных вершин, обрабатываемых на текущей итерации
	list<Vertex<T>*> oldFront;

	// Список текущих помеченных вершин, обрабатываемых на следующей итерации
	list<Vertex<T>*> newFront;

	// Дискретное время (номер итерации)
	int t = 0;

	Vertex<T>* vertexFrom = FindVertex(from);
	Vertex<T>* vertexTo = FindVertex(to);

	// если начальная и конечная вершины совпадают
	if (from == to)
	{
		FoundVertices.push_back(vertexFrom);
		return;
	}

	// Если начальная и конечная вершины присутствуют в графе
	if (vertexFrom != nullptr && vertexTo != nullptr)
	{
		// Перебрать множество вершин и пометить их как непосещённые
		for (unordered_map<T, Vertex<T>*>::iterator i = vertices->begin(); i != vertices->end(); i++) {
			i->second->label = -1;
		}

		// Пометить начальную вершину как посещённую и поместить в список для текущей обработки
		vertexFrom->label = 0;
		oldFront.push_back(vertexFrom);

		// Пока не закончились помеченные вершины с необработанными соседями
		while (oldFront.size() > 0) {

			// Перебрать все помеченные вершины с необработанными соседями (перебрать все вершины в oldFront)
			for (Vertex<T>* vertex : oldFront)
			{
				// Для текущей вершины перебрать множество соседних вершин
				for (Link<T>* link : vertex->links) {

					// найти указатель на соседнюю вершину
					Vertex<T>* current = link->to;

					// Если текущая вершина оказалась искомой
					if (current == vertexTo) {

						current->label = t + 1;
						Vertex<T>* reverse = current;

						// Цикл по вершинам для возврата назад
						while (reverse->label > 0)
						{
							FoundVertices.push_back(reverse);

							// перебрать все соседние вершины для текущей на пути назад
							for (Link<T>* link : reverse->links)
							{
								// если у текущей соседней вершины номер метки на 1 меньше метки вершины reverse
								if (link->from->label == reverse->label - 1)
								{
									// продвинуться на 1 шаг назад
									reverse = link->from;
									break;
								}
							}
						}

						// добавление начальной вершины в ответ
						FoundVertices.push_back(vertexFrom);

						// переворот списка результирующих вершин
						FoundVertices.reverse();

						// Конец алгоритма
						return;
					}

					// если текущая соседняя вершина не помечена
					if (current->label == -1)
					{
						// то пометить её номером шага алгоритма
						current->label = t + 1;

						// добавить найденную вершину в "новый фронт волны"
						newFront.push_back(current);
					}
				}

			}

			// перемещение вершин из нового фронта волны в старый (который будет обрабатываться на следующем шаге)
			oldFront.clear();
			copy(newFront.begin(), newFront.end(), back_inserter(oldFront));
			newFront.clear();

			// увеличить номер шага
			t++;
		}
	}
	throw exception("Incorrect vertex names!");
}

// печать результата поиска
template <class T>
void Graph<T>::PrintFoundPath()
{
	for (list<Vertex<T>*>::iterator i = FoundVertices.begin(); i != FoundVertices.end(); i++) {
		cout << (*i)->title << " ";
	}
}
void main()
{
	Graph<string> graph("test");

	graph.AddVertex("A", 10);
	graph.AddVertex("B", 20);
	graph.AddVertex("C", 30);
	graph.AddVertex("D", 25);
	graph.AddVertex("E", 21);

	graph.AddLink("A", "B", "link1", 12);
	graph.AddLink("B", "C", "link2", 23);
	graph.AddLink("D", "E", "link3", 2);
	graph.AddLink("C", "D", "link4", 21);
	graph.AddLink("B", "E", "link4", 21);

	graph.Print();

	/*graph.RemoveVertex("A");
	graph.RemoveVertex("B");

	graph.Print();*/

	

	graph.GetRoute("A", "A");
	graph.PrintFoundPath();
}