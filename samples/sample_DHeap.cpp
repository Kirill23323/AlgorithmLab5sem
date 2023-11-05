#include "DHeap.hpp"
#include <map>
#include <vector>
#include <locale>
#include <cmath>
#include <fstream>
#include <string>
int main() 
{
  setlocale(LC_ALL, "rus");
  int d = 2;
  std::string line;
  std::ifstream gr;
  gr.open("graph1.txt");
  std::map<int, std::vector<std::vector<int>>>graph;
  int key, num1, num2;
  while (gr >> key) {
    std::vector<std::vector<int>> edges;
    int k = 4;
    while (k != 0)
    {
      gr >> num1;
      gr >> num2;
      std::vector<int> edge;
      edge.push_back(num1);
      edge.push_back(num2);
      edges.push_back(edge);
      k--;
    }
    graph[key] = edges;
  }
  gr.close();
  DHeap h(d, graph);
  h.LDG_DIJKSTRA_DHEAP(1);
  h.PrintDist(1);
  
  return 0;
}