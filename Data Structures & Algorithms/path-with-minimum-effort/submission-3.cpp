/// Alhamdulillah
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumEffortPath(vector<vector<int>> &heights) {
    int n = heights.size();
    int m = heights[0].size();

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    vector<int> cost(n * m, INT_MAX);

    int ans = INT_MAX;

    pq.push({0, 0});
    cost[0] = 0;

    while (!pq.empty()) {
      auto [currCost, node] = pq.top();
      pq.pop();

      vector<pair<int, int>> neigh = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

      for (auto x : neigh) {
        int curr_i = node / m;
        int i = node / m + x.first;

        int curr_j = node % m;
        int j = node % m + x.second;

        if (0 <= i && i < n && 0 <= j && j < m) {
          if (max(currCost, abs(heights[curr_i][curr_j] - heights[i][j])) <
              cost[m * i + j]) {
            cost[m * i + j] =
                max(currCost, abs(heights[curr_i][curr_j] - heights[i][j]));

            pq.push({cost[m * i + j], m * i + j});
          }
        }
      }
    }

    return cost[n * m - 1];
  }
};