#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxArea(vector<int> &heights) {
    int l = 0, r = heights.size() - 1, ans = 0;
    while (l < r) {
      ans = max(ans, min(heights[r], heights[l]) * (r - l));
      heights[l] <= heights[r]? l++:r--;
    }
    return ans;
  }
};