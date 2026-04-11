#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    map<char, bool> found;
    int ans = 0, left = 0;
    for (int i = 0; i < s.size(); i++) {
      if (found[s[i]] == true) {
        while (s[left] != s[i]) {
          found[s[left]] = false;
          left++;
        }
        left++;
      } else
        found[s[i]] = true;

      ans = max(ans, i - left + 1);
    }
    return ans;
  }
};