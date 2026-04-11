#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void backtrack(int i, int n, int k, vector<vector<int>> &ans,
                 vector<int> curr) {
    if (i > n) {
      if (curr.size() == k)
        ans.emplace_back(curr);
      return;
    }

    backtrack(i + 1, n, k, ans, curr);
    curr.emplace_back(i);
    backtrack(i + 1, n, k, ans, curr);
  }

  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    backtrack(1, n, k, ans, {});
    return ans;
  }
};