#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool ans = false;
  map<int, bool> mp;
  bool recur(int i, int curr, int &target, vector<int> &nums) {
    if (curr == target) {
      mp[i] = true;
      return true;
    }

    if (i >= nums.size())
      return false;

    if (mp[i])
      return mp[i];

    bool take = recur(i + 1, curr + nums[i], target, nums);
    bool skip = recur(i + 1, curr, target, nums);

    return mp[i] = take || skip;
  }

  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2)
      return false;
    sum /= 2;

    return recur(0, 0, sum, nums);
  }
};