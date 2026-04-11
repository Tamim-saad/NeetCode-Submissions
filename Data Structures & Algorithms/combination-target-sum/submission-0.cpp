// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void backTrack(vector<int> curr, int sum, int start, int target,
                 vector<int> &nums, vector<vector<int>> &ans) {

    if (sum > target) {
      return;
    }
    if (sum == target) {
      ans.push_back(curr);
      return;
    }

    for (int i = start; i < nums.size(); i++) {
      curr.push_back(nums[i]);
      backTrack(curr, sum + nums[i], i, target, nums, ans);
      curr.pop_back();
    }
  }

  vector<vector<int>> combinationSum(vector<int> &nums, int target) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    backTrack({}, 0, 0, target, nums, ans);
    return ans;
  }
};
