#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool recur(int &k, int start, vector<int> sides, int &len,
             vector<int> &nums) {
    if (start >= nums.size())
      return true;

    for (int i = 0; i < k; i++) {
      if (sides[i] + nums[start] <= len) {

        sides[i] += nums[start];
        if (recur(k, start + 1, sides, len, nums))
          return true;

        sides[i] -= nums[start];
      }

      if (sides[i] == 0)
        break;
    }

    return false;
  }

  bool canPartitionKSubsets(vector<int> &nums, int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k)
      return false;
    vector<int> sides(k, 0);
    sum /= k;
    sort(nums.rbegin(), nums.rend());

    return recur(k, 0, sides, sum, nums);
  }
};