// say Alhamdulillah

#include <bits/stdc++.h>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
#define ll long long

class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    ll n = nums.size();
    ll sum = abs(accumulate(nums.begin(), nums.end(), 0));
    vector<vector<ll>> dp(n + 1, vector<ll>(2 * sum + 2, 0));
    dp[0][sum] = 1;

    for (ll i = 1; i <= nums.size(); i++) {
      for (ll j = 0; j <= 2 * sum; j++) {
        ll x = nums[i - 1];
        if (0 <= j - x && j - x <= 2 * sum + 1 && dp[i - 1][j - x]) dp[i][j] += dp[i - 1][j - x];
        if (0 <= j + x && j + x <= 2 * sum + 1 && dp[i - 1][j + x]) dp[i][j] += dp[i - 1][j + x];
      }
    }
    // for (ll i = 0; i <= nums.size(); i++) {
    //   for (ll j = 0; j <= 2 * sum; j++) {
    //     cout << dp[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    return dp[nums.size()][sum + target];
  }
};