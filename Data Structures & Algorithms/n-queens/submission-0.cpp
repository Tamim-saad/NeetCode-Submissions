#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<string>> ans;
  int n;

  bool isPossible(vector<string> &board, int x, int y) {
    for (int r = 0; r < x; r++) {
      if (board[r][y] == 'Q')
        return false;
    }
    for (int c = 0; c < y; c++) {
      if (board[x][c] == 'Q')
        return false;
    }

    int r = x - 1, c = y - 1;
    while (r >= 0 && c >= 0) {
      if (board[r][c] == 'Q')
        return false;
      r--;
      c--;
    }

    r = x - 1, c = y + 1;
    while (r >= 0 && c < board[0].size()) {
      if (board[r][c] == 'Q')
        return false;
      r--;
      c++;
    }
    return true;
  }

  void dfs(vector<string> &board, int r) {
    if (r == board.size()) {
      ans.emplace_back(board);
      return;
    }

    for (int c = 0; c < board[0].size(); c++) {
      if (isPossible(board, r, c)) {
        board[r][c] = 'Q';
        dfs(board, r + 1);
        board[r][c] = '.';
      }
    }
  }

  vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    dfs(board, 0);
    return ans;
  }
};