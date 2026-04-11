#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int subsetXORSum(vector<int> &nums) {
    int xr = 0;
    for (auto x : nums) {
      xr |= x;
    }

    return xr * pow(2, nums.size() - 1);
  }
};

// Another Solution
//  class Solution {
//  public:
//    int backtrack(int i, int xr, vector<int> nums) {
//      if (i >= nums.size())
//        return xr;

//     return backtrack(i + 1, xr ^ nums[i], nums) + backtrack(i + 1, xr, nums);
//   }

//   int subsetXORSum(vector<int> &nums) { return backtrack(0, 0, nums); }
// };