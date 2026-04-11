#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int ans = 1;
  vector<pair<int, int>> neighbour = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  void dfs(vector<vector<int>> &board, int r, int c, int prev, int cnt) {
    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() ||
        board[r][c] == -1)
      return;

    auto curr = board[r][c];
    if (curr <= prev)
      return;

    cnt++;
    ans = max(ans, cnt);
    auto temp = board[r][c];
    board[r][c] = -1;

    for (auto &[x, y] : neighbour)
      dfs(board, r + x, c + y, curr, cnt);

    board[r][c] = temp;
  }

  int longestIncreasingPath(vector<vector<int>> &matrix) {
    for (int r = 0; r < matrix.size(); r++) {
      for (int c = 0; c < matrix[0].size(); c++) {
        dfs(matrix, r, c, INT_MIN, 0);
      }
    }

    return ans;
  }
};
