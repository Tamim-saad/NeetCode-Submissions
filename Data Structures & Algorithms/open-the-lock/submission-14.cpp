/// Alhamdulillah
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
  vector<string> neighbours(string &lock) {
    vector<string> ans;
    for (int i = 0; i < 4; i++) {
      string next = lock;
      next[i] = (next[i] - '0' + 1) % 10 + '0';
      ans.emplace_back(next);

      next = lock;
      next[i] = (next[i] - '0' - 1 + 10) % 10 + '0';
      ans.emplace_back(next);
    }
    return ans;
  }

public:
  int openLock(vector<string> &deadends, string target) {
    unordered_map<string, int> visited, dead;

    for (auto &x : deadends)
      dead[x] = 1;
    if (dead["0000"])
      return -1;

    queue<pair<int, string>> pq;
    pq.push({0, "0000"});

    while (!pq.empty()) {
      auto [currStep, currLock] = pq.front();
      pq.pop();

      if (target == currLock)
        return currStep;

      if (visited[currLock])
        continue;
      visited[currLock] = 1;

      for (auto &neigh : neighbours(currLock)) {
        if (!dead[neigh] && !visited[neigh]) {
          pq.push({currStep + 1, neigh});
          visited[currLock] = 1;
        }
      }
    }
    return -1;
  }
};