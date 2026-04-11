#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
  string we = "";
  TrieNode *children[26];

  TrieNode() {
    for (int i = 0; i < 26; i++)
      children[i] = nullptr;
  }
};

class Solution {
public:
  TrieNode *root;
  vector<string> ans;
  vector<pair<int, int>> neighbour = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  void insert(string word) {
    auto node = root;

    for (auto ch : word) {
      int ind = ch - 'a';
      if (!node->children[ind])
        node->children[ind] = new TrieNode();
      node = node->children[ind];
    }
    node->we = word;
  }

  void dfs(vector<vector<char>> &board, int r, int c, TrieNode *root) {
    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() ||
        board[r][c] == '#')
      return;

    auto ind = board[r][c] - 'a';
    if (!root->children[ind])
      return;

    root = root->children[ind];
    if (!root->we.empty()) {
      ans.emplace_back(root->we);
      root->we = "";
    }

    auto temp = board[r][c];
    board[r][c] = '#';

    for (auto &[x, y] : neighbour)
      dfs(board, r + x, c + y, root);

    board[r][c] = temp;
  }

  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    root = new TrieNode();

    for (auto &x : words) {
      insert(x);
    }

    for (int r = 0; r < board.size(); r++) {
      for (int c = 0; c < board[0].size(); c++) {
        auto node = root;
        dfs(board, r, c, node);
      }
    }

    return ans;
  }
};