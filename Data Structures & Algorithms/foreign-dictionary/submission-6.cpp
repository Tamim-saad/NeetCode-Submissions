#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string topoSortByKahn(map<char, vector<char>> &neighbours, set<char> &chars) {
    map<char, int> inDegree;
    for (auto &x : chars)
      inDegree[x] = 0;

    for (auto &x : neighbours) {
      for (auto &y : x.second)
        inDegree[y]++;
    }
    queue<char> q;

    for (auto &x : inDegree) {
      if (x.second == 0)
        q.push(x.first);
    }

    string ans = "";

    while (!q.empty()) {
      auto x = q.front();
      q.pop();
      ans += x;

      for (auto neigh : neighbours[x]) {
        inDegree[neigh]--;
        if (inDegree[neigh] == 0)
          q.push(neigh);
      }
    }
    return ans;
  }

  string foreignDictionary(vector<string> &words) {
    if (words.size() == 1)
      return words[0];

    map<char, vector<char>> neighbours;
    set<char> chars;
    for (auto &x : words) {
      for (auto &c : x) {
        chars.insert(c);
      }
    }

    for (int i = 1; i < words.size(); i++) {
      auto x = words[i - 1];
      auto y = words[i];

      auto it = mismatch(x.begin(), x.end(), y.begin());
      if (it.first == x.end() || it.second == y.end()) {
        if (x.size() > y.size())
          return "";
        continue;
      }

      if (it.first != x.end() && it.second != y.end()) {
        auto u = x[it.first - x.begin()];
        auto v = y[it.second - y.begin()];
        neighbours[u].emplace_back(v);
      }
    }

    string ans = topoSortByKahn(neighbours, chars);
    return ans.size() == chars.size() ? ans : "";
  }
};