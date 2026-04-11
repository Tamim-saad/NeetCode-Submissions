#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1));

    for (int i = 0; i < dp.size(); i++) {
      for (int j = 0; j < dp[0].size(); j++) {
        if (i == 0)
          dp[i][j] = -1;
        else if (j == 0)
          dp[i][j] = 0;
      }
    }

    for (int i = 1; i < dp.size(); i++) {
      for (int j = 1; j < dp[0].size(); j++) {
        if (j - coins[i - 1] >= 0) {
          int in = dp[i][j - coins[i - 1]];
          int out = dp[i - 1][j];
          if (in != -1 && out != -1)
            dp[i][j] = min(1+in, out);
          else if (in == -1)
            dp[i][j] = out;
          else if (out == -1)
            dp[i][j] = 1+in;
          else
            dp[i][j] = -1;
        } else
          dp[i][j] = dp[i - 1][j];
      }
    }

    return dp[coins.size()][amount];
  }
};