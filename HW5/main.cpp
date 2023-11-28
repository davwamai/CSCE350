// Copyright 2023 David Wamai
#include <iostream>
#include <vector>
#include <queue>

const int N = 7;

std::vector<std::vector<int>> p1adjMatrix(N, std::vector<int>(N, 0));

std::vector<int> parent(N, -1);
std::vector<bool> visited(N, false);

void BFS(int s) {
  std::queue<int> q;

  visited[s] = true;
  parent[s] = s;
  q.push(s);

  while (!q.empty()) {
    int current = q.front();
    q.pop();

    for (int i = 0; i < N; i++) {
      if (p1adjMatrix[current][i] == 1 && !visited[i]) {
        visited[i] = 1;
        q.push(i);
        parent[i] = current;
      }
    }
  }
}


int main() {
  std::vector<std::pair<int, int>> edges = {{0, 1}, {0, 2}, {0, 3},{0, 4},
                                           {1, 0}, {1, 3}, {1, 5},
                                           {2,0}, {2, 6},
                                           {3, 0}, {3, 1}, {3, 5},   
                                           {4, 0}, {4, 6}, 
                                           {5, 1}, {5, 3},
                                           {6, 2}, {6, 4}};

  for (auto edge : edges) {
    int u = edge.first;
    int v = edge.second;
    p1adjMatrix[u][v] = 1;
    p1adjMatrix[v][u] = 1;
  }
  std::cout << "Graph in Adjacency Matrix Format" << std::endl;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cout << p1adjMatrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  BFS(0);
  std::cout << "BFS Forest (Node: Parent)\n";
  for (int i = 0; i < N; i++) {
    std::cout << char('a'+ i) << ": " << char('a' + parent[i]) << std::endl;
  }
  std::cout << std::endl;

  

  return 0;
}
