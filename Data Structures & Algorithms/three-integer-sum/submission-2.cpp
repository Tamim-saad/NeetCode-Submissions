#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    set<vector<int>> st;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
      int piv = nums[i];
      int l = i + 1;
      int r = nums.size() - 1;

      while (l < r) {
        if (l < r && piv + nums[l] + nums[r] == 0) {
          st.insert({piv, nums[l], nums[r]});
          l++;
          r--;
        } else if (piv + nums[l] + nums[r] > 0)
          r--;
        else
          l++;
      }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
  }
};