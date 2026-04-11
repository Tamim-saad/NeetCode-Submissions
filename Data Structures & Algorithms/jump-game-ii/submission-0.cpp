// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int jump(vector<int> &nums) {
    vector<int> ans(nums.size(), INT_MAX);
    ans[0] = 0;
    for (int i = 0; i < nums.size(); i++) {
      int x = nums[i];
      for (int j = 1; j <= x && i + j < nums.size(); j++) {
        ans[i + j] = min(ans[i + j], ans[i] + 1);
      }
    }
    return ans.back();
  }
};