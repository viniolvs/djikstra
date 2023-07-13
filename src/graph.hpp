#include <climits>
#include <iostream>
#include <queue>
#include <vector>

class Graph {
private:
  int numVertices;
  std::vector<std::vector<int>> adjMatrix;

public:
  Graph(int numVertices) {
    this->numVertices = numVertices;
    adjMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
  }

  void addEdge(int src, int dest, int weight = 1) {
    if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices) {
      adjMatrix[src][dest] = weight;
      adjMatrix[dest][src] = weight;
    }
  }
  int findMinDistance(const std::vector<int> &distances,
                      const std::vector<bool> &visited) {
    int minDistance = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < numVertices; ++i) {
      if (!visited[i] && distances[i] < minDistance) {
        minDistance = distances[i];
        minIndex = i;
      }
    }
    return minIndex;
  }

  void dijkstraList(int startVertex, bool print = false) {
    std::vector<int> distances(numVertices, INT_MAX);
    std::vector<bool> visited(numVertices, false);

    distances[startVertex] = 0;

    for (int i = 0; i < numVertices - 1; ++i) {
      int u = findMinDistance(distances, visited);
      visited[u] = true;

      for (int v = 0; v < numVertices; ++v) {
        if (!visited[v] && adjMatrix[u][v] != 0 && distances[u] != INT_MAX &&
            distances[u] + adjMatrix[u][v] < distances[v]) {
          distances[v] = distances[u] + adjMatrix[u][v];
        }
      }
    }

    if (print) {
      std::cout << "Shortest distances from vertex " << startVertex << ":\n";
      for (int i = 0; i < numVertices; ++i) {
        std::cout << "Vertex " << i << ": " << distances[i] << std::endl;
      }
    }
  }

  struct HeapNode {
    int vertex;
    int distance;

    HeapNode(int vertex, int distance) : vertex(vertex), distance(distance) {}
  };

  void dijkstraHeap(int startVertex, bool print = false) {
    std::vector<int> distances(numVertices, INT_MAX);
    std::vector<bool> visited(numVertices, false);

    distances[startVertex] = 0;

    auto compare = [](const HeapNode &a, const HeapNode &b) {
      return a.distance > b.distance;
    };
    std::priority_queue<HeapNode, std::vector<HeapNode>, decltype(compare)>
        minHeap(compare);
    minHeap.push(HeapNode(startVertex, 0));

    while (!minHeap.empty()) {
      int u = minHeap.top().vertex;
      minHeap.pop();

      if (visited[u])
        continue;

      visited[u] = true;

      for (int v = 0; v < numVertices; ++v) {
        if (adjMatrix[u][v] != 0 && distances[u] != INT_MAX &&
            distances[u] + adjMatrix[u][v] < distances[v]) {
          distances[v] = distances[u] + adjMatrix[u][v];
          minHeap.push(HeapNode(v, distances[v]));
        }
      }
    }

    if (print) {
      std::cout << "Shortest distances from vertex " << startVertex << ":\n";
      for (int i = 0; i < numVertices; ++i) {
        std::cout << "Vertex " << i << ": " << distances[i] << std::endl;
      }
    }
  }

  void printGraph() {
    for (int i = 0; i < numVertices; ++i) {
      for (int j = 0; j < numVertices; ++j) {
        std::cout << adjMatrix[i][j] << ",";
      }
      std::cout << std::endl;
    }
  }

  void readAdjMatrix() {
    for (int i = 0; i < numVertices; ++i) {
      for (int j = 0; j < numVertices; ++j) {
        std::cin >> adjMatrix[i][j];
      }
    }
  }
};
