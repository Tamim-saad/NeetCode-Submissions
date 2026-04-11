// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> partitionLabels(string s) {
    map<char, int> mp;
    map<char, int> start;
    map<char, int> end;
    for (int i = 0; i < s.length(); i++) {
      char ch = s[i];
      if (mp.find(ch) != mp.end()) {
        mp.insert({ch, 1});
        start[ch] = i;
      } else {
        end[ch] = i;
      }
    }
    vector<int> ans;
    int l = 0, r = 0;
    while (r < s.length()) {
      int t = end[s[l]];
      while (++r <= t) {
        t = max(t, end[s[r]]);
      }
      ans.push_back(t - l + 1);
      l = r = t + 1;
    }
    return ans;
  }
};