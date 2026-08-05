#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> ans;
  vector<string> v = {"",    "",    "abc",  "def", "ghi",
                      "jkl", "mno", "pqrs", "tuv", "wxyz"};

  void recur(int i, string curr, string &digits) {
    if (i >= digits.size()) {
      ans.emplace_back(curr);
      return;
    }

    for (auto x : v[digits[i] - '0'])
      recur(i + 1, curr + x, digits);
  }
  vector<string> letterCombinations(string digits) {
    if (digits.empty())
      return {};
    string curr = "";
    recur(0, curr, digits);
    return ans;
  }
};
