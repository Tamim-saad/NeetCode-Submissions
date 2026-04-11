class Solution {
 public:
  void islandsAndTreasure(vector<vector<int>>& grid) {
    queue<pair<int, int>> q;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (!grid[i][j]) {
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
      if (i < grid.size() - 1 && grid[i + 1][j] == INT_MAX) {
        grid[i + 1][j] = 1 + grid[i][j];
        q.push({i + 1, j});
      }
      if (j && grid[i][j - 1] == INT_MAX) {
        grid[i][j - 1] = 1 + grid[i][j];
        q.push({i, j - 1});
      }
      if (j < grid[i].size() - 1 && grid[i][j + 1] == INT_MAX) {
        grid[i][j + 1] = 1 + grid[i][j];
        q.push({i, j + 1});
      }
    }
  }
};