/// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canReach(string s, int minJump, int maxJump) {
    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < s.size(); i++) {
      if (i < minJump)
        continue;

      if (s[i] == '1') {
        dp[i] = -1;
        continue;
      }

      for (int j = max(i - maxJump, 0); j <= i - minJump; j++) {
        if (dp[j] == 1) {
          dp[i] = 1;
          break;
        }
      }
    }

    return dp[s.size() - 1] == 1;
  }
};