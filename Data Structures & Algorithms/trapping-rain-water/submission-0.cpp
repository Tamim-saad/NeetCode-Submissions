#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    int n = height.size();
    int l = 0, r = n - 1;
    while (l < r && height[l] <= height[l + 1])
      l++;
    while (l < r && height[r] <= height[r - 1])
      r--;

    int li = l, ri = r;
    int ans = 0;

    while (l < r) {
      if (li < ri && height[li] <= height[ri]) {
        l = li;
        r = ri;
        while (l < r && height[li] >= height[l]) {
          ans += height[li] - height[l];
          l++;
        }
        if (l < r) {
          li = l;
        }
      } else if (li < ri) {
        l = li;
        r = ri;
        while (l < r && height[ri] >= height[r]) {
          ans += height[ri] - height[r];
          r--;
        }
        if (l < r) {
          ri = r;
        }
      }
    }

    return ans;
  }
};