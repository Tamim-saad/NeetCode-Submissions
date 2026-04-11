#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool differByOne(string &a, string &b) {
    int diff = 0;
    for (int i = 0; i < a.size(); i++)
      diff += (a[i] != b[i]);
    return diff == 1;
  }

  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {

    if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
      return 0;

    wordList.insert(wordList.begin(), beginWord);
    int n = wordList.size();
    vector<vector<int>> neighbours(n);

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (differByOne(wordList[i], wordList[j])) {
          neighbours[j].emplace_back(i);
          neighbours[i].emplace_back(j);
        }
      }
    }

    vector<bool> visited(n, false);
    queue<pair<int, int>> q;

    q.push({0, 1});
    visited[0] = true;

    while (!q.empty()) {
      auto [curr, step] = q.front();
      q.pop();

      if (wordList[curr] == endWord)
        return step;

      for (auto neigh : neighbours[curr]) {
        if (!visited[neigh]) {
          visited[neigh] = true;
          q.push({neigh, step + 1});
        }
      }
    }

    return 0;
  }
};