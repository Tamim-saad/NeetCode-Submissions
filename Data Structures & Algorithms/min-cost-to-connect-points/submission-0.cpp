/// Alhamdulillah
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minCostConnectPoints(vector<vector<int>> &points) {
    int w, n = points.size();
    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        adj[j].push_back({w, i});
        adj[i].push_back({w, j});
      }
    }

    vector<int> value(n, INT_MAX), parent(n, -1);
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    pq.push({0, 0});
    value[0] = 0;

    while (!pq.empty()) {
      int curr = pq.top().second;
      int currWeight = pq.top().first;
      pq.pop();

      if (visited[curr])
        continue;
      visited[curr] = true;

      for (auto neighbor : adj[curr]) {
        int nextNode = neighbor.second;
        int edgeWeight = neighbor.first;

        if (!visited[nextNode] && edgeWeight < value[nextNode]) {
          parent[nextNode] = curr;
          value[nextNode] = edgeWeight;
          pq.push({value[nextNode], nextNode});
        }
      }
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
      ans += value[i];
    }

    return ans;
  }
};