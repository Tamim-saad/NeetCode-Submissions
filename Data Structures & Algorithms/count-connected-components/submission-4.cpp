#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> adj_list;
  vector<int> par, vis;

  void dfs(int curr) {
    if (vis[curr])
      return;
    vis[curr] = 1;

    for (auto neigh : adj_list[curr])
      dfs(neigh);

    return;
  }

  int countComponents(int n, vector<vector<int>> &edges) {
    vis.resize(n, 0);
    adj_list.resize(n);

    for (auto x : edges) {
      adj_list[x[0]].emplace_back(x[1]);
      adj_list[x[1]].emplace_back(x[0]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        ans++;
        dfs(i);
      }
    }

    return ans;
  }
};