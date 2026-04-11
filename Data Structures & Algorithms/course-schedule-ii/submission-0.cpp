// say Alhamdulillah

#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;

// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     indexed_multiset;

#define ll unsigned long long
class Solution {
 public:
  vector<vector<int>> adj_list;
  vector<int> par, vis, inDegree, vans;

  vector<int> findOrder(int n, vector<vector<int>>& edges) {
    vis.resize(n, 0);
    inDegree.resize(n, 0);
    adj_list.resize(n);

    for (auto x : edges) {
      adj_list[x[1]].emplace_back(x[0]);
      inDegree[x[0]]++;
      if (x[0] == x[1]) return {};
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (inDegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
      auto x = q.front();
      q.pop();
      if (vis[x]) continue;

      vis[x] = 1;
      vans.emplace_back(x);

      for (auto neigh : adj_list[x]) {
        if (inDegree[neigh] > 0) inDegree[neigh]--;
        if (inDegree[neigh] == 0) q.push(neigh);
      }
    }
    if (vans.size() != n) return {};
    return vans;
  }
};