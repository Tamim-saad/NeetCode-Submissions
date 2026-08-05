#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> mp;
  bool recur(int i, int curr, int &target, vector<int> &nums) {
    if (curr == target)
      return true;

    if (i >= nums.size() || curr > target)
      return false;

    if (mp[i][curr] != -1)
      return mp[i][curr];

    bool take = recur(i + 1, curr + nums[i], target, nums);
    bool skip = recur(i + 1, curr, target, nums);

    return mp[i][curr] = take || skip;
  }

  bool canPartition(vector<int> &nums) {

    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2)
      return false;
    sum /= 2;

    mp.resize(nums.size() + 1, vector<int>(sum + 1, -1));

    return recur(0, 0, sum, nums);
  }
};