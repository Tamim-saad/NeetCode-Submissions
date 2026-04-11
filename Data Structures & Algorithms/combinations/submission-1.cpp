#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> ans;
  void backtrack(int i, int &n, int &k, vector<int> &curr) {
    if (curr.size() == k) {
      ans.emplace_back(curr);
      return;
    }

    if (curr.size() > k || i > n)
      return;

    curr.emplace_back(i);
    backtrack(i + 1, n, k, curr);
    curr.pop_back();

    backtrack(i + 1, n, k, curr);
  }

  vector<vector<int>> combine(int n, int k) {
    vector<int> curr;
    backtrack(1, n, k, curr);
    return ans;
  }
};