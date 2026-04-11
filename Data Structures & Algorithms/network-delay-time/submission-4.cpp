/// Alhamdulillah
#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
  int prims(int n, int k, vector<vector<pair<int, int>>> &adj_list) {
    vector<int> value(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    pq.push({0, k});
    value[k] = 0;

    while (!pq.empty()) {
      int currWeight = pq.top().first;
      int curr = pq.top().second;
      pq.pop();

      if (visited[curr])
        continue;
      visited[curr] = true;

      for (auto [nextNode, edgeWeight] : adj_list[curr]) {
        if (!visited[nextNode] && value[curr] + edgeWeight < value[nextNode]) {
          value[nextNode] = value[curr] + edgeWeight;
          pq.push({value[nextNode], nextNode});
        }
      }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (!visited[i])
        return -1;
      ans = max(ans, value[i]);
    }
    return ans;
  }

  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    vector<vector<pair<int, int>>> adj_list(n + 1);
    for (int i = 0; i < times.size(); i++)
      adj_list[times[i][0]].push_back({times[i][1], times[i][2]});

    return prims(n, k, adj_list);
  }
};
