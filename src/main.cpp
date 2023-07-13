#include "graph.hpp"
#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char **argv) {
  int n;
  cin >> n;
  Graph graph(n);
  graph.readAdjMatrix();
  // Executa o algoritmo de Dijkstra
  // grava o tempo de execução
  clock_t start, end;

  // imprime o tempo de execução
  graph.printGraph();

  start = clock();
  graph.dijkstraList(0, true);
  /* graph.dijkstraHeap(0, true); */
  end = clock();

  double time = ((static_cast<double>(end - start) + 0.0) / CLOCKS_PER_SEC);
  printf("Tempo de execução: %f\n", time);
  return 0;
}
