/// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int combinationSum4(vector<int> &nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 0; i <= target; i++) {
      if (dp[i]) {
        for (auto x : nums) {
          if (i + x <= target)
            dp[i + x] += dp[i];
        }
      }
    }
    return dp[target];
  }
};