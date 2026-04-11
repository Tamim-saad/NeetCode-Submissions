/// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> dp;
  int rec(string s, int i) {
    if (i == s.size())
      return 1;
    if (i > s.size() || s[i] == '0')
      return 0;
    if (dp[i] != -1)
      return dp[i];

    dp[i] = rec(s, i + 1);

    int y = 0, val;
    val = stoi(s.substr(i, 2));

    if (val >= 10 && val <= 26)
      y = rec(s, i + 2);

    return dp[i] += y;
  }

  int numDecodings(string s) {
    dp.resize(s.size() + 1, -1);
    return rec(s, 0);
  }
};