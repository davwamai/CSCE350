// Copyright 2023 David Wamai
#include <iostream>
#include <vector>
#include <queue>

const int N = 7;

std::vector<std::vector<int>> adjMatrix(N, std::vector<int>(N, 0));

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
      if (adjMatrix[current][i] == 1 && !visited[i]) {
        visited[i] = 1;
        q.push(i);
        parent[i] = current;
      }
    }
  }
}

// a function that prints the path from source to destination
// using the parent array
void printPath(int s, int d) {
  if (s == d) {
    std::cout << char('a' + s) << " ";
    return;
  }
  printPath(s, parent[d]);
  std::cout << char('a' + d) << " ";
}

int main() {
  // FIXME: find comfortable init parameters
  std::vector<std::pair<int, int>> edges = {{2, 0}, {3, 0}, {4, 0},
                                    {0, 2}, {4, 5}, {5, 6}, {4, 6}};
  for (auto edge : edges) {
    int u = edge.first;
    int v = edge.second;
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
  }
  std::cout << "Graph in Adjacency Matrix Format" << std::endl;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cout << adjMatrix[i][j] << " ";
    }
    std::cout << std::endl;
  }

  BFS(0);
  std::cout << "BFS Forest (Node: Parent)\n";
  for (int i = 0; i < N; i++) {
    std::cout << char('a'+ i) << ": " << char('a' + parent[i]) << std::endl;
  }
  return 0;
}
