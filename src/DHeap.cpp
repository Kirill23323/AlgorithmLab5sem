#include "DHeap.hpp"
#define __max(a,b)  (((a) > (b)) ? (a) : (b))
#define __min(a,b)  (((a) < (b)) ? (a) : (b))

DHeap::DHeap(int d, std::map<int, std::vector<std::vector<int>>> Graph)
{
	n = Graph.size();
	if (n == 0)
		throw "err";
	nq = n;
	this->d = d;
	if (d < 2)
		throw "error";
	ADJ = new vtype * [n + 1];
	for (int i = 0; i < n + 1; i++) 
	{
		ADJ[i] = nullptr;
	}
	key = new int[n + 1];
	name = new int[n + 1];
	index = new int[n + 1];
	dist = new int[n + 1];
	up = new int[n + 1];
	visited = new bool[n + 1];
	key1 = 0;
	name1 = 0;
	FormGraph(ADJ, Graph, n);

}

DHeap::DHeap(int d,int n,int m,int q,int r)
{
	this->n = abs(n);
	if (n == 0)
		throw "error";
	nq = n;
	this->d = d;
	if (d < 2)
		throw "error";
	ADJ = new vtype * [n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		ADJ[i] = nullptr;
	}
	key = new int[n + 1];
	name = new int[n + 1];
	index = new int[n + 1];
	dist = new int[n + 1];
	up = new int[n + 1];
	visited = new bool[n + 1];
	key1 = 0;
	name1 = 0;
	if(n == 1)
		FormGraphForExp(ADJ, n, 0, abs(q), abs(r));
	else
		FormGraphForExp(ADJ, n, abs(m), abs(q), abs(r));
}

DHeap::~DHeap()
{
	delete[] index;
	delete[] key;
	delete[] name;
	delete[] dist;
	delete[] up;
	delete[] visited;

	for (int i = 0; i < n; i++)
	{
		vtype* current = ADJ[i];
		while (current != nullptr)
		{
			vtype* nextNode = current->next;
			delete current;
			current = nextNode;
		}
	}
	delete[] ADJ;
}

int DHeap::MinChild(int i, int* key, int n, int d)
{
	int kf = FirstChild(n, d, i);
	if (kf == 0)
		return i;
	else
	{
		int kl = LastChild(n, d, i);
		int minKey = key[kf];
		int minChild = kf;
		for (int j = kf + 1; j < kl; j++)
		{
			if (key[j] < minKey)
			{
				minKey = key[kf];
				minChild = j;
			}
		}
		return minChild;
	}
}

int DHeap::FirstChild(int n, int d, int i)
{
	int k = (i - 1) * d + 2;
	if (k > n)
		return 0;
	else
		return k;
}

int DHeap::LastChild(int n, int d, int i)
{
	int k = FirstChild(n, d, i);
	if (k == 0)
		return 0;
	else
		return __min(k + d - 1, n);
}

int DHeap::Father(int n, int d, int i)
{
	return (i - 2) / d + 1;
}

void DHeap::PrintDist(int s)
{
	std::fstream file;
	file.open("sampleOutput.txt", std::fstream::out);
	for (int i = 1; i < this->n + 1; i++)
	{
		std::cout << "Кратчайшее расстояние от вершины " << s << " до вершины " << i << " = " << this->dist[i] << std::endl;
		file << "Кратчайшее расстояние от вершины " << s << " до вершины " << i << " = " << this->dist[i] << std::endl;
	}
	file.close();
}

void DHeap::SetD(int d)
{
	this->d = d;
}

void DHeap::Dipping(int i, int* name, int* key,int n, int d)
{
	int key0 = key[i];
	int name0 = name[i];
	int c = MinChild(i, key, n, d);
	while ((c != i) && (key0 > key[c]))
	{
		this->key[i] = key[c];
		this->name[i] = name[c];
		this->index[name[i]] = i;
		i = c;
		c = MinChild(i, key, n, d);
	}
	this->key[i] = key0;
	this->name[i] = name0;
	this->index[name[i]] = i;
}


void DHeap::Ascent(int i, int* name, int* key, int n, int d)
{
	int key0 = key[i];
	int name0 = name[i];
	int p = Father(n, d, i);
	while ((i != 1) && (key[p] > key0))
	{
		this->key[i] = key[p];
		this->name[i] = name[p];
		this->index[name[i]] = i;
		i = p;
		p = Father(n, d, i);
	}
	this->key[i] = key0;
	this->name[i] = name0;
	this->index[name[i]] = i;
}

void DHeap::TakeMin(int name1, int key1, int* name, int* key,int n, int d)
{
	this->name1 = name[1];
	this->key1 = key[1];
	this->name[1] = name[n];
	this->key[1] = key[n];
	n--;
	if (n > 1)
		Dipping(1, name, key, n, d);
}

void DHeap::LDG_DIJKSTRA_DHEAP(int s)
{
	int i, j, jq = 0;
	this->name[0], this->index[0], this->dist[0], this->up[0], this->key[0] = 0;
	this->visited[0] = false;
	vtype* p;
	int prev = s;
	for (int i = 1; i < n + 1; i++)
	{
		name[i] = i;
		index[i] = i;
		dist[i] = INT_MAX;
		up[i] = 0;
		key[i] = INT_MAX;
		visited[i] = false;
	}
	key[s] = 0;
	if (s != 1) 
		Ascent(s, name, key, n, d);
	FormAQueue(name,key,nq,d);
	while (nq > 0)
	{
		TakeMinNq(name1, key1, name, key, nq, d);
		i = name1;
		dist[i] = key1;
		p = ADJ[i];
		while (p != nullptr)
		{
			j = p->name;
			if (visited[j])
			{
				p = p->next;
				continue;
			}
			jq = index[j];
			if (key[jq] > dist[i] + p->w) 
			{

				key[jq] = dist[i] + p->w;
				Ascent(jq, name, key, nq, d);
				up[j] = i;
			}
			p = p->next;
		}
		visited[i] = true;

	}
	nq = n;
	//PrintDist(s); 
}



void DHeap::FormAQueue(int* name, int* key, int n, int d)
{
	for (int i = n; i >= 1; i--)
	{
		Dipping(i, name, key, n, d);
	}
}

void FormGraph(ADJtype ADJ, std::map<int, std::vector<std::vector<int>>> Graph, int n)
{
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 0; j < Graph.at(i).size(); j++)
		{
			vtype* newNode = GetAdjListNode(Graph.at(i)[j][0], Graph.at(i)[j][1],ADJ[i]);
			ADJ[i] = newNode;
		}
	}
}
vtype* GetAdjListNode(int value, int weight, vtype* head)
{
	vtype* newNode = new vtype;
	newNode->name = value;
	newNode->w = weight;
	newNode->next = head;

	return newNode;
}
void FormGraphForExp(ADJtype ADJ,int n,int m,int q,int r)
{
	int w = 0;
	for (int i = 1; i < n + 1; i++)
	{
		if (m == 0)
			break;
		for (int j = i + 1; j < n + 1; j++)
		{
			w = Random(q, r);
			vtype* newNode = GetAdjListNode(j, w, ADJ[i]);
			ADJ[i] = newNode;
			newNode = GetAdjListNode(i, w, ADJ[j]);
			ADJ[j] = newNode;
			m -= 2;
			if (m == 0)
				break;
		}
	}
}
int Random(int low, int high)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(low, high);
	return dist(gen);
}
void DHeap::TakeMinNq(int name1, int key1, int* name, int* key, int nq, int d)
{
	this->name1 = name[1];
	this->key1 = key[1];
	this->name[1] = name[nq];
	this->key[1] = key[nq];
	this->nq--;
	if (this->nq > 1)
		Dipping(1, name, key, this->nq, d);
}