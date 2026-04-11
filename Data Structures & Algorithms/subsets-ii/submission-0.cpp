// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void backTrack(vector<int> curr, int start, vector<int> &nums,
                 vector<vector<int>> &ans) {

    ans.push_back(curr);

    for (int i = start; i < nums.size(); i++) {
      if (start < i && nums[i] == nums[i - 1])
        continue;
      curr.push_back(nums[i]);
      backTrack(curr, i + 1, nums, ans);
      curr.pop_back();
    }
  }

  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    backTrack({}, 0, nums, ans);
    return ans;
  }
};
