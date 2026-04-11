// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    vector<int> vans;
    int n = nums.size();

    // for (auto x : nums) {
    for (int i = 0; i < n; i++) {
      int x = nums[i];
      if (vans.empty() || vans.back() < x)
        vans.push_back(x);
      else {
        int ind = lower_bound(vans.begin(), vans.end(), x) - vans.begin();
        vans[ind] = x;
      }
    }
    return vans.size();
  }
};