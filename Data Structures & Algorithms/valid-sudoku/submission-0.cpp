// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isValidRow(vector<vector<char>> &b, int r) {
    bool ans = false;
    map<char, int> mp;
    for (int i = 0; i < 9; i++) {
      if (b[r][i] != '.')
        mp[b[r][i]]++;
    }
    for (auto x : mp) {
      if (x.second > 1)
        return false;
    }
    return true;
  }
  bool isValidCol(vector<vector<char>> &b, int c) {
    bool ans = false;
    map<char, int> mp;
    for (int i = 0; i < 9; i++) {
      if (b[i][c] != '.')
        mp[b[i][c]]++;
    }
    for (auto x : mp) {
      if (x.second > 1)
        return false;
    }
    return true;
  }
  bool isValidBox(vector<vector<char>> &b, int r, int c) {
    bool ans = false;
    map<char, int> mp;
    for (int i = r; i < r + 3; i++) {
      for (int j = c; j < c + 3; j++) {
        if (b[i][j] != '.')
          mp[b[i][j]]++;
      }
    }
    for (auto x : mp) {
      if (x.second > 1)
        return false;
    }
    return true;
  }
  bool isValidSudoku(vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
      if (!isValidRow(board, i))
        return false;
      if (!isValidCol(board, i))
        return false;
    }
    for (int i = 0; i < 9; i += 3) {
      for (int j = 0; j < 9; j += 3) {
        if (!isValidBox(board, i, j))
          return false;
      }
    }
    return true;
  }
};
