#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> left(nums.size(),0);
    vector<int> right(nums.size(),0);
    vector<int> ans(nums.size(),0);

    int k = 1;
    for (int i = 0; i < nums.size(); i++) {
      left[i] = k;
      k *= nums[i];
    }
    k = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
      right[i] = k;
      k *= nums[i];
    }

    for (int i = 0; i < nums.size(); i++) {
      ans[i] = left[i] * right[i];
    }

    return ans;
  }
};
