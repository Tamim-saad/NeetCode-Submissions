// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    int l = 0, m;
    int h = nums.size() - 1;
    while (l < h) {
      m = (l + h) / 2;

      if (nums[m] > nums[h])
        l = m + 1;
      else
        h = m;
    }
    return nums[l];
  }
};