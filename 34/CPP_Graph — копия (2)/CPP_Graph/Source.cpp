#pragma once
#include <unordered_map>
#include <string>
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

	// �������� �������
	string title;

	// ����� �������
	unsigned int id;

	// ��� ������� �����
	int weight;

	// ����, ���������� � ������ �������
	list<Link<T>*> links;

	// �������� ����� ������ � ������ �������
	bool RemoveLink(unsigned int linkId);

	// ����� �������, ����� ��� ������ ���������� ������
	int label;
public:
	Vertex(unsigned int id, const string title, int weight);
	~Vertex();

	// �������� �������� �������
	string GetTitle();

	// �������� ���� �������
	unsigned int GetId();

	// ���������� ���������� �������� ����
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
	// ������� ���� ���� �������� � ��������� �������
	typename list<Link<T>*>::iterator pos = links.begin();
	while (pos != links.end())
	{
		// ��������� �� ������� �����
		Link<T>* currentLink = *(pos);

		pos++;

		// �������� �������� �����
		delete currentLink;
	}

	// �������� ������ ���� ���� �������
	//links.clear();
}

// �������� ���� �� Id � ������� ��� �������� �� � �������� �������
template <class T>
bool Vertex<T>::RemoveLink(unsigned int linkId)
{
	typename list<Link<T>*>::iterator pos;
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

// ������� ���������� ����, �������� � �������
template <class T>
unsigned int Vertex<T>::GetLinksCount()
{
	return links.size();
}

// ���������� Id �������
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

	// ��������� ��� �������� ���� � ������� � ��� ����� Print
	typename list<Link<T>*>::iterator pos;
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

	// ��������� �� �������, �� ������� ��� �����
	Vertex<T>* from;

	// ��������� �� �������, � ������� ��� �����
	Vertex<T>* to;

	// �������� �����
	string title;

	// ����� �����
	unsigned int id;

	// ��� ����� �����
	int weight;
public:
	Link(unsigned int id, const string title, int weight, Vertex<T>* from, Vertex<T>* to);
	~Link();

	// �������� ����� �����
	unsigned int GetId();

	// �������� �������� �����
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
	// ������� ��������� �� ��������� ����� � ������� ��������
	from->RemoveLink(id);
	to->RemoveLink(id);
}

// ���������� Id �����
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
	// �������� �����
	T title;

	// ����� ��������� �������, ������� ����� �������
	unsigned int vertexId = 0;

	// ���������� ������ �����
	unsigned int vertexCount = 0;

	// ����� ���������� �����, ������� ����� ������
	unsigned int linkId = 0;

	// ���������� ���� �����
	unsigned int linkCount = 0;

	// ��������� �� ������ ������ �����
	unordered_map<T, Vertex<T>*>* vertices;

public:

	// �������������� ������ �������� ������ - ����� ���������� ������
	list<Vertex<T>*> FoundVertices;

	Graph(const T title);
	~Graph();

	// ������� ������� � ������ ������ �� � ��������
	Vertex<T>* FindVertex(const T title);

	// ���������� ������� � ����
	unsigned int AddVertex(const T title, unsigned int weight);

	// ���������� �����, ������������ ��� �������
	unsigned int AddLink(const T from, const T to, const T title, unsigned int weight);

	// �������� ������� �� Id
	bool RemoveVertex(unsigned int vertexId);

	// �������� ������� �� ��������
	bool RemoveVertex(const T title);

	// �������� �������� ��� ������������� �����
	void GetRoute(T from, T to);

	// ������ ���������� ������
	void PrintFoundPath();

	void Print();

	/*list<T>dfs();
	void dfs(Vertex<T>* v, list<T>& res);*/
};
template <class T>
Graph<T>::Graph(const T _title)
{
	this->title = _title;

	// ��������� ������ ��� ������ ������
	vertices = new unordered_map<T, Vertex<T>*>();
}
template <class T>
Graph<T>::~Graph()
{
	// ������� ������ ������ � �������� ������ �������
	typename unordered_map<T, Vertex<T>*>::iterator pos = vertices->begin();
	while (pos != vertices->end())
	{
		// ��������� �� ������� �������
		Vertex<T>* currentVertex = pos->second;

		// ����������� ��������� �� ��������� �������
		pos++;

		// ������� ������� �������
		delete currentVertex;
	}

	// �������� ������ ������ �����
	delete vertices;
}

// ����� ������� �� ��������
template <class T>
Vertex<T>* Graph<T>::FindVertex(const T title)
{
	typename unordered_map<T, Vertex<T>*>::iterator pos = vertices->find(title);
	if (pos != vertices->end())
		return pos->second;

	return nullptr;
}

// ���������� ������� � ����
template <class T>
unsigned int Graph<T>::AddVertex(const T title, unsigned int weight)
{
	if (FindVertex(title) == 0)
	{
		Vertex<T>* vertex = new Vertex<T>(vertexId++, title, weight);
		if (vertex != nullptr)
		{
			// ���������� ������� � ������ ������
			vertices->insert(make_pair(title, vertex));

			// ��������� ���������� ������ �� 1
			vertexCount++;

			// ���������� Id ��������� �������
			return vertexId - 1;
		}
	}
	return -1;
}
template <class T>
unsigned int Graph<T>::AddLink(const T from, const T to, const T title, unsigned int weight)
{
	// �������� ��������� �� ������� �� �� ���������
	Vertex<T>* vertexFrom = FindVertex(from);
	Vertex<T>* vertexTo = FindVertex(to);

	if (vertexFrom != nullptr && vertexTo != nullptr)
	{
		// �������� ������� �����
		Link<T>* link = new Link<T>(linkId++, title, weight, vertexFrom, vertexTo);
		if (link != nullptr)
		{
			// ���������� ���������� �� ��������� ����� � ������ ���� ������ �� ����������� ������
			vertexFrom->links.push_back(link);
			vertexTo->links.push_back(link);

			// ��������� ���������� ���� �� 1
			linkCount++;

			// ���������� Id ���������� �����
			return linkId - 1;
		}
	}

	return -1;
}

// �������� ������� �� Id
template <class T>
bool Graph<T>::RemoveVertex(unsigned int vertexId)
{
	// ������� ������ ������
	typename unordered_map<T, Vertex<T>*>::iterator pos;
	for (pos = vertices->begin(); pos != vertices->end(); pos++)
	{
		Vertex<T>* currentVertex = pos->second;

		// ���� ������� ������ �������
		if (currentVertex->id == vertexId)
		{
			// �� ������ ���������� ���� ����� ������� ���������� ����, ���������� � ��������� �������
			linkCount -= currentVertex->GetLinksCount();

			// ��������� ���������� ������ �� 1
			vertexCount--;

			// �������� �������
			delete currentVertex;

			vertices->erase(pos);

			return true;
		}
	}

	return false;
}

// �������� ������� �� ��������
template <class T>
bool Graph<T>::RemoveVertex(const T title)
{
	typename unordered_map<T, Vertex<T>*>::iterator pos;
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

	// ��������� ������ ������ � ���������� ��� �������
	typename unordered_map<T, Vertex<T>*>::iterator pos;
	for (pos = vertices->begin(); pos != vertices->end(); pos++)
	{
		pos->second->Print();
	}
}

// �������� �������� ��� ������������� �����
template <class T>
void Graph<T>::GetRoute(T from, T to)
{

	// �������� ���������� ���������
	FoundVertices.clear();

	// ������ ������� ������������� ������, �������������� �� ������� ��������
	list<Vertex<T>*> oldFront;

	// ������ ������� ���������� ������, �������������� �� ��������� ��������
	list<Vertex<T>*> newFront;

	// ���������� ����� (����� ��������)
	int t = 0;

	Vertex<T>* vertexFrom = FindVertex(from);
	Vertex<T>* vertexTo = FindVertex(to);

	// ���� ��������� � �������� ������� ���������
	if (from == to)
	{
		FoundVertices.push_back(vertexFrom);
		return;
	}

	// ���� ��������� � �������� ������� ������������ � �����
	if (vertexFrom != nullptr && vertexTo != nullptr)
	{
		// ��������� ��������� ������ � �������� �� ��� ������������
		for (typename unordered_map<T, Vertex<T>*>::iterator i = vertices->begin(); i != vertices->end(); i++) {
			i->second->label = -1;
		}

		// �������� ��������� ������� ��� ���������� � ��������� � ������ ��� ������� ���������
		vertexFrom->label = 0;
		oldFront.push_back(vertexFrom);

		// ���� �� ����������� ���������� ������� � ��������������� ��������
		while (oldFront.size() > 0) {

			// ��������� ��� ���������� ������� � ��������������� �������� (��������� ��� ������� � oldFront)
			for (Vertex<T>* vertex : oldFront)
			{
				// ��� ������� ������� ��������� ��������� �������� ������
				for (Link<T>* link : vertex->links) {

					// ����� ��������� �� �������� �������
					Vertex<T>* current = link->to;

					// ���� ������� ������� ��������� �������
					if (current == vertexTo) {

						current->label = t + 1;
						Vertex<T>* reverse = current;

						// ���� �� �������� ��� �������� �����
						while (reverse->label > 0)
						{
							FoundVertices.push_back(reverse);

							// ��������� ��� �������� ������� ��� ������� �� ���� �����
							for (Link<T>* link : reverse->links)
							{
								// ���� � ������� �������� ������� ����� ����� �� 1 ������ ����� ������� reverse
								if (link->from->label == reverse->label - 1)
								{
									// ������������ �� 1 ��� �����
									reverse = link->from;
									break;
								}
							}
						}

						// ���������� ��������� ������� � �����
						FoundVertices.push_back(vertexFrom);

						// ��������� ������ �������������� ������
						FoundVertices.reverse();

						// ����� ���������
						return;
					}

					// ���� ������� �������� ������� �� ��������
					if (current->label == -1)
					{
						// �� �������� � ������� ���� ���������
						current->label = t + 1;

						// �������� ��������� ������� � "����� ����� �����"
						newFront.push_back(current);
					}
				}

			}

			// ����������� ������ �� ������ ������ ����� � ������ (������� ����� �������������� �� ��������� ����)
			oldFront.clear();
			copy(newFront.begin(), newFront.end(), back_inserter(oldFront));
			newFront.clear();

			// ��������� ����� ����
			t++;
		}
	}
	throw exception("Incorrect vertex names!");
}

// ������ ���������� ������
template <class T>
void Graph<T>::PrintFoundPath()
{
	for (typename list<Vertex<T>*>::iterator i = FoundVertices.begin(); i != FoundVertices.end(); i++) {
		cout << (*i)->title << " ";
	}
}


//template <class T>
//list<T> Graph<T>::dfs() 
//{
//	typename list<Vertex<T>*>::iterator it = FoundVertices.begin();
//	typename list<Vertex<T>*>::iterator ite = FoundVertices.end();
//	
//	for (; it != ite; it++)
//		(*it)->visited = false;
//	vector<T> res;
//	it = FoundVertices.begin();
//	for (; it != ite; it++)
//		if ((*it)->visited == false)
//			dfs(*it, res);
//	return res;
//}
//
//template <class T>
//void Graph<T>::dfs(Vertex<T>* v, list<T>& res)
//{
//	v->visited = true;
//	res.push_back(v->info);
//	typename list<Link<T> >::iterator it = (v->adj).begin();
//	typename list<Link<T> >::iterator ite = (v->adj).end();
//	for (; it != ite; it++)
//		if (it->dest->visited == false)
//			dfs(it->dest, res);
//}

int main()
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



	
	//graph.dfs("A", "A");
	graph.PrintFoundPath();
}