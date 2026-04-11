/// Alhamdulillah
#include <bits/stdc++.h>
#include <climits>
using namespace std;

class DSU {
public:
  struct Node {
    // int value;
    int parent = -1;
    int rank = 0;
  };

  Node node[100];

  struct edge_sort {
    bool operator()(vector<int> const &v1, vector<int> const &v2) {
      return v1[2] > v2[2];
    }
  };

  int FindParent(int u) {
    if (node[u].parent == -1)
      return u;
    return node[u].parent = FindParent(node[u].parent);
  }

  bool Union(int u, int v) {
    int pu = FindParent(u);
    int pv = FindParent(v);

    if (pu == pv)
      return false;

    if (node[pu].rank == node[pv].rank)
      node[pu].rank++;

    if (node[pu].rank >= node[pv].rank)
      node[pv].parent = pu;
    else if (node[pu].rank < node[pv].rank)
      node[pu].parent = pv;

    return true;
  }

  int kruskal(int n, vector<vector<int>> edges, int to_include, int to_remove) {
    for (int i = 0; i < n; i++) {
      node[i].parent = -1;
      node[i].rank = 0;
    }

    int ans = 0;
    if (to_include != -1) {
      Union(edges[to_include][0], edges[to_include][1]);
      ans += edges[to_include][2];
    }

    priority_queue<vector<int>, vector<vector<int>>, edge_sort> pq;

    for (int i = 0; i < edges.size(); i++) {
      if (i == to_include || i == to_remove)
        continue;
      pq.push({edges[i][0], edges[i][1], edges[i][2]});
    }

    while (!pq.empty()) {
      auto e = pq.top();
      pq.pop();

      if (Union(e[0], e[1]))
        ans += e[2];
    }

    for (int i = 1; i < n; i++) {
      if (FindParent(i) != FindParent(0))
        return INT_MAX;
    }

    return ans;
  }
};

class Solution {
public:
  vector<vector<int>>
  findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges) {

    auto dsu = new DSU();
    int ans = dsu->kruskal(n, edges, -1, -1);
    vector<int> critical, pCritical;

    cout << ans << endl;

    for (int i = 0; i < edges.size(); i++) {
      auto newEdges = edges;

      int include = dsu->kruskal(n, newEdges, i, -1);
      int exclude = dsu->kruskal(n, newEdges, -1, i);

      if (exclude > ans) {
        critical.emplace_back(i);
        continue;
      }
      if (include == ans) {
        pCritical.emplace_back(i);
      }
    }

    return {critical, pCritical};
  }
};