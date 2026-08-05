#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int mini = 1, maxi = 1, ans = nums[0];

    for (auto x : nums) {
      int mn = min({mini * x, maxi * x, x});
      int mx = max({mini * x, maxi * x, x});
      maxi = mx;
      mini = mn;

      ans = max(ans, maxi);
    }

    return ans;
  }
};
