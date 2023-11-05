#include <iostream>
#include <vector>
#include <map>
#include <random>
#include<fstream>
struct vtype { 
	int name; 
	int w; 
	vtype* next; 
};
typedef vtype** ADJtype;
void FormGraph(ADJtype ADJ, std::map<int, std::vector<std::vector<int>>> Graph, int n); 
vtype* GetAdjListNode(int value, int weight, vtype* head); 
void FormGraphForExp(ADJtype ADJ,int n,int m,int q,int r); 
int Random(int low, int high); 
class DHeap 
{
protected:
	int n; 
	int d; 
	ADJtype ADJ; 
	int* index; 
	int* key;  
	int* name; 
	int* dist; 
	int* up; 
	bool* visited; 
	int key1; 
	int name1; 
	int nq; 
public:
	DHeap(int d,std::map<int,std::vector<std::vector<int>>> Graph);
	DHeap(int d,int n,int m,int q,int r); 
	~DHeap(); 
	int MinChild(int i, int* key, int n, int d); 
	int FirstChild(int n, int d, int i);
	int LastChild(int n, int d, int i);
	int Father(int n, int d, int i); 
	void Dipping(int i, int* name, int* key, int n, int d); 
	void Ascent(int i, int* name, int* key, int n, int d); 
	void TakeMin(int name1, int key1, int* name, int* key, int n, int d); 
	void TakeMinNq(int name1, int key1, int* name, int* key, int nq, int d); 
	void FormAQueue(int* name, int* key, int n, int d); 
	void LDG_DIJKSTRA_DHEAP(int s); 
	void PrintDist(int s); 
	void SetD(int d); 
};
