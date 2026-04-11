// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void backTrack(string curr, int open, int close, int n, vector<string> &ans) {
    if (curr.size() == 2 * n) {
      ans.push_back(curr);
    }
    if (open < n) {
      backTrack(curr + '(', open + 1, close, n, ans);
    }
    if (close < open) {
      backTrack(curr + ')', open, close + 1, n, ans);
    }
  }
  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    backTrack("", 0, 0, n, ans);
    return ans;
  }
};
