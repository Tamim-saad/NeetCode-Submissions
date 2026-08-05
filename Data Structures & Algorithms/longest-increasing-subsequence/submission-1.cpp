#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    vector<int> vans;

    for (auto x : nums)
      if (vans.empty() || vans.back() < x)
        vans.push_back(x);
      else
        vans[lower_bound(vans.begin(), vans.end(), x) - vans.begin()] = x;

    return vans.size();
  }
};