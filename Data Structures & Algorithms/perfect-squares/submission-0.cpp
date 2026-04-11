#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i * i <= n; i++)
      dp[i * i] = 1;

    for (int i = 1; i <= n; i++) {
      for (int k = 1; k * k <= i; k++) {
        if (dp[i - k * k])
          dp[i] = min(dp[i], 1 + dp[i - k * k]);
      }
    }

    return dp[n];
  }
};