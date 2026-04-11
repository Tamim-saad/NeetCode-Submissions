// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> ans;
    map<string, vector<string>> mp;
    for (auto x : strs) {
      string t = x;
      sort(t.begin(), t.end());
      mp[t].push_back(x);
    }
    for (auto x : mp) {
      ans.push_back(x.second);
    }
    return ans;
  }
};
