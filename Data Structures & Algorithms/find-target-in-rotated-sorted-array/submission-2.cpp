// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int n = nums.size();
    int l = 0;
    int h = n - 1;
    int ans;

    while (l <= h) {
      int m = (l + h) / 2;

      if (nums[m] == target)
        return m;

      if (nums[l] <= nums[m]) {

        if (nums[l] <= target && target <= nums[m]) {
          h = m;
        } else
          l = m + 1;

      } else {

        if (nums[m] <= target && target <= nums[h]) {
          l = m;
        } else
          h = m - 1;
      }
    }
    return -1;
  }
};