/// Alhamdulillah
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    int n = heights.size();
    int m = heights[0].size();

    queue<pair<int, int>> pq;
    map<pair<int, int>, pair<int, int>> mp;
    map<pair<int, int>, int> visited;

    for (int i = 0; i < m; i++) {
      pq.push({0, i});
      mp[{0, i}].first = 1;
    }
    for (int i = 0; i < n; i++) {
      pq.push({i, 0});
      mp[{i, 0}].first = 1;
    }

    while (!pq.empty()) {
      auto [curr_i, curr_j] = pq.front();
      pq.pop();

      if (visited[{curr_i, curr_j}]) {
        continue;
      }
      visited[{curr_i, curr_j}] = 1;

      vector<pair<int, int>> neigh = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

      for (auto x : neigh) {
        int i = curr_i + x.first;
        int j = curr_j + x.second;
        int currRise = heights[curr_i][curr_j];

        if (0 <= i && i < n && 0 <= j && j < m) {
          if (currRise <= heights[i][j]) {
            pq.push({i, j});
            mp[{i, j}].first = 1;
          }
        }
      }
    }

    //------------------------------------------
    for (int i = 0; i < m; i++) {
      pq.push({n - 1, i});
      mp[{n - 1, i}].second = 1;
    }
    for (int i = 0; i < n; i++) {
      pq.push({i, m - 1});
      mp[{i, m - 1}].second = 1;
    }
    visited.clear();

    while (!pq.empty()) {
      auto [curr_i, curr_j] = pq.front();
      pq.pop();

      if (visited[{curr_i, curr_j}]) {
        continue;
      }
      visited[{curr_i, curr_j}] = 1;

      vector<pair<int, int>> neigh = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

      for (auto x : neigh) {
        int i = curr_i + x.first;
        int j = curr_j + x.second;
        int currRise = heights[curr_i][curr_j];

        if (0 <= i && i < n && 0 <= j && j < m) {
          if (currRise <= heights[i][j]) {
            pq.push({i, j});
            mp[{i, j}].second = 1;
          }
        }
      }
    }
    //---------------------------------------------------

    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (mp[{i, j}].first && mp[{i, j}].second) {
          ans.push_back({i, j});
        }
      }
    }

    return ans;
  }
};