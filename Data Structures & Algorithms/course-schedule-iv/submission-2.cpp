

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &prerequisites,
                                   vector<vector<int>> &queries) {
    vector<int> inDegree(n, 0);
    vector<vector<int>> neighbours(n);

    for (auto &x : prerequisites) {
      neighbours[x[0]].emplace_back(x[1]);
      inDegree[x[1]]++;
    }

    queue<int> q;
    for (int i = 0; i < inDegree.size(); i++) {
      if (inDegree[i] == 0)
        q.push(i);
    }

    vector<bitset<100>> dp(n);

    while (!q.empty()) {
      auto curr = q.front();
      q.pop();

      for (auto neigh : neighbours[curr]) {
        dp[neigh] |= dp[curr];
        dp[neigh].set(curr);

        inDegree[neigh]--;
        if (inDegree[neigh] == 0)
          q.push(neigh);
      }
    }

    vector<bool> ans(queries.size(), false);
    for (int i = 0; i < queries.size(); i++) {
      auto x = queries[i];
      if (dp[x[1]][x[0]])
        ans[i] = true;
    }

    return ans;
  }
};