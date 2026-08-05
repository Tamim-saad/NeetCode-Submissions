#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int change(int amount, vector<int> &coins) {
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));

    for (int i = 0; i <= coins.size(); i++)
      dp[i][0] = 1;

    for (int i = 1; i <= coins.size(); i++) {
      int cn = coins[i - 1];
      for (int a = 0; a <= amount; a++) {
        dp[i][a] = dp[i - 1][a];
        if (a >= cn)
          dp[i][a] += dp[i][a - cn];
      }
    }
    return dp[coins.size()][amount];
  }
};
