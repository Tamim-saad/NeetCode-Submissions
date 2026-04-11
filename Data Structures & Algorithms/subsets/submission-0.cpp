// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void backTrack(vector<int> curr, int start, vector<int> &nums,
                 vector<vector<int>> &ans) {

    if (start >= nums.size()) {
      ans.push_back(curr);
      return;
    }

    backTrack(curr, start + 1, nums, ans);
    curr.push_back(nums[start]);
    backTrack(curr, start + 1, nums, ans);
  }

  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans;
    backTrack({}, 0, nums, ans);
    return ans;
  }
};
