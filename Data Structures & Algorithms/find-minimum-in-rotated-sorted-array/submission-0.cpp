// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    int n = nums.size();
    int l = 0;
    int h =n - 1;
    int ans,m;

    while (l <= h) {
      if (nums[l] < nums[h]) {
        ans = nums[l];
        return ans;
      }
      m = (l + h) / 2;
      ans=nums[m];

      // cout<<nums[m]<<endl;

      if (nums[l] <= nums[m]) {
        l = m + 1;
      } else {
        h = m;
      }
    }
    return ans;
  }
};