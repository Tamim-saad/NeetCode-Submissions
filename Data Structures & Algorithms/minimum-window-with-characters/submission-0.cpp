#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    map<char, int> pattern, mp;

    for (auto &x : t)
      pattern[x]++;

    int i = 0, j = 0, cnt = 0, n = t.size();
    string ans = "";

    while (i < s.size()) {
      mp[s[i]]++;

      if (mp[s[i]] <= pattern[s[i]])
        cnt++;

      while (j <= i && mp[s[j]] > pattern[s[j]]) {
        mp[s[j]]--;
        j++;
      }

      if (cnt == n && (ans.empty() || i - j + 1 < ans.length()))
        ans = s.substr(j, i - j + 1);

      i++;
    }

    return ans;
  }
};