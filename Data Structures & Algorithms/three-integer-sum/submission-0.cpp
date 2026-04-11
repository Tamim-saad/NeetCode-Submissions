#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    // vector<vector<int>> ans;
    set<vector<int>> st;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
      int piv = nums[i];
      int l = i + 1;
      int r = nums.size() - 1;

      while (l < r) {
        if (l < r && piv + nums[l] + nums[r] == 0) {
          int mini = min(piv, min(nums[l], nums[r]));
          int maxi = max(piv, max(nums[l], nums[r]));
          int mid = piv + nums[l] + nums[r] - mini - maxi;
          // // if (1map [{mini, mid, maxi}])
          st.insert({mini, mid, maxi});
            // ans.push_back({mini, mid, maxi});
            // cout<<piv<<" "<<nums[l]<<" "<<nums[r]<<endl;
          l++;
          r--;
        } else if (piv + nums[l] + nums[r] > 0)
          r--;
        else
          l++;
      }
    }
    // for(auto x: st)
    // {
    //   for(auto y: x)
    //   cout<<y<<" ";
    // cout<<endl;
    // }
     vector<vector<int>> ans(st.begin(),st.end());
    return ans;
  }
};