// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool subsetSumCheck(vector<int> &nums, int target) {
    vector<vector<bool>> dp(nums.size() + 1, vector<bool>(target + 1, false));
    for (int i = 0; i <= nums.size(); i++)
      dp[i][0] = true;

    for (int i = 1; i <= nums.size(); i++) {
      for (int j = 0; j <= target; j++) {
        bool exclude = dp[i - 1][j];
        bool include = false;
        if (j - nums[i - 1] >= 0)
          include = dp[i - 1][j - nums[i - 1]];
        dp[i][j] = include || exclude;
      }
    }
    return dp[nums.size()][target];
  }
  bool canPartition(vector<int> &nums) {
    int sum = 0;
    for (auto x : nums) {
      sum += x;
    }
    if (sum % 2 == 1)
      return false;
    else
      return subsetSumCheck(nums, sum / 2);
  }
};