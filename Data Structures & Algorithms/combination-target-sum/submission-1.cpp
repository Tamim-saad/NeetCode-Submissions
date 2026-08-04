#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void backTrack(vector<int> curr, int sum, int start, int target,
                 vector<int> &nums, vector<vector<int>> &ans) {

    if (sum > target || start >= nums.size())
      return;

    if (sum == target) {
      ans.push_back(curr);
      return;
    }

    curr.push_back(nums[start]);
    backTrack(curr, sum + nums[start], start, target, nums, ans);
    curr.pop_back();
    backTrack(curr, sum, start + 1, target, nums, ans);
  }

  vector<vector<int>> combinationSum(vector<int> &nums, int target) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    backTrack({}, 0, 0, target, nums, ans);
    return ans;
  }
};
