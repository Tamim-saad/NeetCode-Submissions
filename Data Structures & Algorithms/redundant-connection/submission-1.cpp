/// Alhamdulillah
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  struct Node {
    int parent = -1;
    int rank = 0;
  };

  map<int, Node> node;

  int FindParent(int u) {
    if (node[u].parent == -1)
      return u;

    return node[u].parent = FindParent(node[u].parent);
  }

  void Union(int u, int v) {
    if (node[u].rank == node[v].rank)
      node[u].rank++;
    if (node[u].rank >= node[v].rank)
      node[v].parent = u;
    else
      node[u].parent = v;
  }

  vector<int> ans;

  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    for (auto e : edges) {
      int pu = FindParent(e[0]);
      int pv = FindParent(e[1]);
      if (pu != pv) {
        Union(pu, pv);
      } else {
        ans = e;
        continue;
      }
    }

    return ans;
  }
};