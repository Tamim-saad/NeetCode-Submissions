// say Alhamdulillah

#include <bits/stdc++.h>
#include <climits>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;

// typedef tree<int, null_type, less<int>, rb_tree_tag,
//              tree_order_statistics_node_update>
//     indexed_multiset;

#define ll unsigned long long
class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          grid[i][j] = INT_MAX;
        }
      }
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 2) {
          q.push({i, j});
        }
      }
    }
    int i, j;
    while (!q.empty()) {
      auto x = q.front();
      q.pop();
      i = x.first;
      j = x.second;
      if (i && grid[i - 1][j] == INT_MAX) {
        grid[i - 1][j] = 1 + grid[i][j];
        q.push({i - 1, j});
      }
      if (i < m - 1 && grid[i + 1][j] == INT_MAX) {
        grid[i + 1][j] = 1 + grid[i][j];
        q.push({i + 1, j});
      }
      if (j && grid[i][j - 1] == INT_MAX) {
        grid[i][j - 1] = 1 + grid[i][j];
        q.push({i, j - 1});
      }
      if (j < n - 1 && grid[i][j + 1] == INT_MAX) {
        grid[i][j + 1] = 1 + grid[i][j];
        q.push({i, j + 1});
      }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == INT_MAX) return -1;
        if (grid[i][j] != 0) ans = max(ans, grid[i][j]);
      }
    }
    return (ans == 0 ? 0 : ans - 2);
  }
};