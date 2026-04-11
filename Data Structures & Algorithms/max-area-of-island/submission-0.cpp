// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // map<pair<int, int>, pair<int, int>> mp;
  // map<pair<int, int>, int> vis;

  void dfs(vector<vector<int>> &grid, int i, int j, int m, int n,
          int &area) {

    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
      return ;
    grid[i][j] = 0;
    area++;

    dfs(grid, i - 1, j, m, n, area);
    dfs(grid, i, j - 1, m, n, area);
    dfs(grid, i + 1, j, m, n, area);
    dfs(grid, i, j + 1, m, n, area);
    // return area;
  }

  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int maxi = 0;
    int m = grid.size();
    int n = grid[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          int area = 0;
          dfs(grid, i, j, m, n, area);
          maxi = max(maxi, area);
        }

        // cout << mp[make_pair(i, j)].first << "." << mp[make_pair(i,
        // j)].second
        //  << "  ";
      }
      // cout << endl;
    }

    return maxi;
  }
};
