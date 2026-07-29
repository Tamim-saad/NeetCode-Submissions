#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int r = nums.size() - 2;
    while (r >= 0 && (nums[r] >= nums[r + 1]))
      r--;

    if (r >= 0) {
      int i = nums.size() - 1;
      while (nums[i] <= nums[r])
        i--;
      swap(nums[r], nums[i]);
    }

    reverse(nums.begin() + r + 1, nums.end());
  }
};
