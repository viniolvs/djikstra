#include "graph.hpp"
#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

int main(int argc, char **argv) {
  if (argc != 2 && argc != 3) {
    cout << "Usage: " << argv[0] << " <list | heap>  <comp | print>" << endl;
    cout << "comp: retorna o número de comparações" << endl;
    cout << "print: imprime o resultado" << endl;
    return 1;
  }

  int n;
  cin >> n;
  Graph graph(n);
  int countComp = 0;
  // Lê a matriz de adjacência
  graph.readAdjMatrix();
  // grava o tempo de execução
  clock_t start, end;
  bool print = false;
  bool comp = false;
  if (argc == 3) {
    if (strcmp(argv[2], "comp") == 0)
      comp = true;
    else if (strcmp(argv[2], "print") == 0)
      print = true;
  }

  // imprime o tempo de execução
  /* graph.printGraph(); */

  start = clock();
  // executa o algoritmo de Dijkstra para cada vértice
  if (comp) {
    if (strcmp(argv[1], "heap") == 0)
      for (int i = 0; i < n; i++)
        countComp = graph.dijkstraHeapComp(i);
    else
      for (int i = 0; i < n; i++)
        countComp = graph.dijkstraListComp(i);
    if (strcmp(argv[1], "heap") == 0)
      for (int i = 0; i < n; i++)
        graph.dijkstraHeap(i, print);
    else
      for (int i = 0; i < n; i++)
        graph.dijkstraList(i, print);
  }
  end = clock();

  if (comp)
    cout << countComp << endl;
  else {
    double time = ((static_cast<double>(end - start) + 0.0) / CLOCKS_PER_SEC);
    printf("%f\n", time);
  }
  return 0;
}
