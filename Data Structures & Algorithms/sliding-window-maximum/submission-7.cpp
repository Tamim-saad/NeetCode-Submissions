#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    if (k == 1)
      return nums;
    vector<int> v;
    int n = nums.size();
    vector<int> vans(n - k + 1);
    for (int i = 0; i < k; i++) {
      v.push_back(nums[i]);
    }
    sort(v.begin(), v.end());

    vans[0] = v.back();
    for (int i = k; i < n; i++) {
      int last = nums[i - k];
      auto it = lower_bound(v.begin(), v.end(), last);
      if (it != v.end()) {
        v.erase(it);
      }
      int add = nums[i];
      v.insert(upper_bound(v.begin(), v.end(), add), add);
      vans[i - k + 1] = v.back();
    }
    return vans;
  }
};