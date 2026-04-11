#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    if (n == 1)
      return {0};
    
    vector<vector<int>> neighbours(n + 1);
    vector<int> inDegree(n + 1, 0);

    for (auto x : edges) {
      neighbours[x[0]].emplace_back(x[1]);
      neighbours[x[1]].emplace_back(x[0]);
      inDegree[x[0]]++;
      inDegree[x[1]]++;
    }

    queue<int> q;

    // for(auto x:inDegree){
    for (int i = 0; i < inDegree.size(); i++) {
      if (inDegree[i] == 1)
        q.push(i);
    }

    int rem = n;
    while (rem > 2) {
      int len = q.size();
      rem -= len;

      for (int i = 0; i < len; i++) {
        auto top = q.front();
        q.pop();
        for (auto x : neighbours[top]) {
          inDegree[x]--;
          if (inDegree[x] == 1) {
            q.push(x);
          }
        }
      }
    }

    vector<int> ans;

    while (!q.empty()) {
      auto top = q.front();
      q.pop();
      ans.emplace_back(top);
    }

    return ans;
  }
};