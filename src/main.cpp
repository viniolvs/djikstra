#include "graph.hpp"
#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

int main(int argc, char **argv) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <list | heap>" << endl;
    return 1;
  }

  int n;
  cin >> n;
  Graph graph(n);
  // Lê a matriz de adjacência
  graph.readAdjMatrix();
  // grava o tempo de execução
  clock_t start, end;

  // imprime o tempo de execução
  /* graph.printGraph(); */

  start = clock();

  // executa o algoritmo de Dijkstra para cada vértice
  if (strcmp(argv[1], "heap") == 0)
    for (int i = 0; i < n; i++)
      graph.dijkstraHeap(i, false);
  else
    for (int i = 0; i < n; i++)
      graph.dijkstraList(i, false);

  end = clock();

  double time = ((static_cast<double>(end - start) + 0.0) / CLOCKS_PER_SEC);
  printf("%f\n", time);

  return 0;
}
