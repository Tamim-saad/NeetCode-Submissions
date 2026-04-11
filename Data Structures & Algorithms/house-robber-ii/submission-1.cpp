// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int help(vector<int> &nums) {
    int l = 0;
    int r = 0;
    for (auto x : nums) {
      int t = r;
      r = max(x + l, r);
      l = t;
    }
    return r;
  }
  int rob(vector<int> &nums) {
    if(nums.size()==1) return nums[0];
    if(nums.size()==2) return max(nums[0], nums[1]);
    if(nums.size()==3) return max(nums[0], max(nums[1], nums[2]));

    vector<int> t0(nums.begin()+1, nums.end());
    vector<int> t1(nums.begin(), nums.end()-1);

    return max(help(t0), help(t1));
  }
};
