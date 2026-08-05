#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    unordered_map<int, int> dp;
    dp[0] = 1;

    for (int x : nums) {
      unordered_map<int, int> nextDp;
      for (auto &[total, count] : dp) {
        nextDp[total + x] += count;
        nextDp[total - x] += count;
      }
      dp = nextDp;
    }
    return dp[target];
  }
};