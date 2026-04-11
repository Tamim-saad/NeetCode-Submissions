/// Alhamdulillah
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    map<int, int> mp;
    int ans = 0, preSum = 0;
    mp[0] = 1;

    for (auto x : nums) {
      preSum += x;
      if (mp[preSum - k])
        ans += mp[preSum - k];

      mp[preSum]++;
    }

    return ans;
  }
};