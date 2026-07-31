#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int r = 1, w = 0;
    while (r < nums.size()) {
      if (nums[w] != nums[r]) {
        nums[++w] = nums[r];
      }
      r++;
    }
    return ++w;
  }
};