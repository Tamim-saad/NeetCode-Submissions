// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool backTrack(int i, int j, int start, vector<vector<char>> &board,
                 string word) {

    if (start == word.size())
      return true;

    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
        board[i][j] != word[start])
      return false;

    char curr = board[i][j];
    board[i][j] = '#';

    bool temp = backTrack(i, j - 1, start + 1, board, word) ||
                backTrack(i, j + 1, start + 1, board, word) ||
                backTrack(i - 1, j, start + 1, board, word) ||
                backTrack(i + 1, j, start + 1, board, word);

    board[i][j] = curr;
    return temp;
  }

  bool exist(vector<vector<char>> &board, string word) {
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (backTrack(i, j, 0, board, word)) {
          return true;
        }
      }
    }
    return false;
  }
};
