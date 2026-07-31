#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int i = 0, j = 0, ans = 0;
    vector<bool> exist(256, false);
    while (j < s.size()) {
      while (i < s.size() && exist[s[j]]) {
        exist[s[i]] = false;
        i++;
      }
      exist[s[j]] = true;
      ans = max(ans, j - i + 1);
      j++;
    }

    return ans;
  }
};
