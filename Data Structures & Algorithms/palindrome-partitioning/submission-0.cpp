#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<string>> ans;
  int n;

  bool isPalindrome(string &s, int l, int r) {
    while (l < r) {
      if (s[l] != s[r])
        return false;

      l++;
      r--;
    }
    return true;
  }

  void dfs(vector<string> curr, int j, int i, string s) {
    if (i >= s.size()) {
      if (i == j)
        ans.emplace_back(curr);
      return;
    }

    if (isPalindrome(s, j, i)) {
      curr.emplace_back(s.substr(j, i - j + 1));
      dfs(curr, i + 1, i + 1, s);
      curr.pop_back();
    }

    dfs(curr, j, i + 1, s);
  }
  vector<vector<string>> partition(string s) {
    dfs({}, 0, 0, s);
    return ans;
  }
};