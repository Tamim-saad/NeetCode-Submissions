#define ll unsigned long long
class Solution {
 public:
  int change(int amount, vector<int>& coins) {
    vector<vector<ll>> dp(coins.size() + 1, vector<ll>(amount + 1, 0));
    for (int i = 0; i <= coins.size(); i++) {
      dp[i][0] = 1;
    }

    for (int i = 1; i <= coins.size(); i++) {
      int cn = coins[i - 1];
      for (int j = 0; j <= amount; j++) {
        dp[i][j] = dp[i - 1][j];
        if (j >= cn) {
          dp[i][j] = dp[i][j] + dp[i][j - cn];
        }
      }
    }
    return (int)(dp[coins.size()][amount]);
  }
};
