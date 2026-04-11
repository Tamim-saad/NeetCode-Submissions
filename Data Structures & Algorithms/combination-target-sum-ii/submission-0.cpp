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
      if (start < i && nums[i] == nums[i - 1])
        continue;
      curr.push_back(nums[i]);
      backTrack(curr, sum + nums[i], i + 1, target, nums, ans);
      curr.pop_back();
    }
  }

  vector<vector<int>> combinationSum2(vector<int> &nums, int target) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    backTrack({}, 0, 0, target, nums, ans);
    return ans;
  }
};
