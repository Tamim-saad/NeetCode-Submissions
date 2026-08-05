#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<pair<int, int>> neigh = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 2)
          q.push({i, j});
      }
    }

    int i, j, ans = 0, ni, nj;
    while (!q.empty()) {
      auto x = q.front();
      q.pop();
      i = x.first;
      j = x.second;

      for (auto x : neigh) {
        ni = i + x.first;
        nj = j + x.second;
        if (0 <= ni && ni < m && 0 <= nj && nj < n && grid[ni][nj] == 1) {
          grid[ni][nj] = 1 + grid[i][j];
          q.push({ni, nj});
        }
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1)
          return -1;
        if (grid[i][j] != 0)
          ans = max(ans, grid[i][j]);
      }
    }

    return ans == 0 ? 0 : ans - 2;
  }
};