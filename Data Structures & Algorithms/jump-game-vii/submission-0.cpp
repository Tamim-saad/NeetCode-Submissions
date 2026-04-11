/// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canReach(string s, int minJump, int maxJump) {
    vector<int> dp(s.size() + 1, 0);
    for (int i = 0; i < s.size(); i++) {
      auto x = s[i];
      if (x == '1')
        dp[i] = -1;
    }

    dp[0] = 1;

    for (int i = 0; i < s.size(); i++) {
      for (int j = minJump; j <= maxJump; j++) {
        if (i + j < s.size() && dp[i] != -1 && dp[i + j] != -1) {
          dp[i + j] |= dp[i];
        }
      }
    }

    return dp[s.size() - 1] == 1;
  }
};