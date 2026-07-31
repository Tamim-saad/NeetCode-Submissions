#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int characterReplacement(string s, int k) {
    unordered_map<char, int> mp;
    int maxi = 0, ans = 0;

    int l = 0, r = 0;
    while (r < s.size()) {
      mp[s[r]]++;
      maxi = max(maxi, mp[s[r]]);
      while (r - l + 1 - maxi > k) {
        mp[s[l]]--;
        l++;
      }
      ans = max(ans, r - l + 1);
      r++;
    }
    return ans;
  }
};
