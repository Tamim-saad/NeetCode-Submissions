/// Alhamdulillah
#include <bits/stdc++.h>
#include <utility>
using namespace std;

struct Node {
  int parent = -1;
  int rank = 0;
  int w = 0;
};

vector<Node> node;
vector<bool> visited;
vector<pair<int, int>> direction = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

int FindParent(int u) {
  if (node[u].parent == -1)
    return u;
  return node[u].parent = FindParent(node[u].parent);
}

void Union(int u, int v) {
  if (node[u].rank >= node[v].rank)
    node[v].parent = u;

  else if (node[u].rank < node[v].rank)
    node[u].parent = v;

  if (node[u].rank == node[v].rank)
    node[u].rank++;
}

class Solution {
public:
  int swimInWater(vector<vector<int>> &grid) {

    int i, n = grid.size();
    vector<pair<int, int>> cells;

    node.assign(n * n, Node());
    visited.assign(n * n, false);

    for (i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cells.push_back({grid[i][j], n * i + j});

    sort(cells.begin(), cells.end());

    for (auto [w, serial] : cells) {
      visited[serial] = true;

      for (auto pr : direction) {
        int x = serial / n + pr.first;
        int y = serial % n + pr.second;

        if (x >= 0 && x < n && y >= 0 && y < n && visited[n * x + y]) {
          int pu = FindParent(serial);
          int pv = FindParent(n * x + y);

          if (pu != pv)
            Union(pu, pv);

          if (FindParent(0) == FindParent(n * n - 1))
            return w;
        }
      }
    }

    return 0;
  }
};