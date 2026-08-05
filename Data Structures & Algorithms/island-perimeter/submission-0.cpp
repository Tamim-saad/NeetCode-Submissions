#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  vector<vector<int>> grid;
  int rows, cols, maxi = 0;

  void dfs(int i, int j, int &curr) {
    if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == 0) {
      maxi = max(maxi, ++curr);
      return;
    }

    if (grid[i][j] == -1)
      return;

    grid[i][j] = -1;

    dfs(i, j + 1, curr);
    dfs(i + 1, j, curr);
    dfs(i, j - 1, curr);
    dfs(i - 1, j, curr);
  }

public:
  int islandPerimeter(vector<vector<int>> &grid) {
    this->grid = grid;
    rows = grid.size();
    cols = grid[0].size();

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        int curr = 0;
        if (grid[i][j] == 1)
          dfs(i, j, curr);
      }
    }
    return maxi;
  }
};