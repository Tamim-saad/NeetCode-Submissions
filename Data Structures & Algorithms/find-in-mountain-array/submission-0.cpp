/// Alhamdulillah
#include <bits/stdc++.h>
using namespace std;

// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
// class MountainArray {
// public:
//   int get(int index);
//   int length();
// };

class Solution {
public:
  int binSearch(int l, int h, int &target, MountainArray &mountainArr,
                bool asc) {

    while (l <= h) {
      int m = (l + h) / 2;
      int midVal = mountainArr.get(m);
      if (midVal == target)
        return m;

      if (asc) {
        if (midVal < target)
          l = m + 1;
        else
          h = m - 1;
      } else {
        if (target > midVal)
          h = m - 1;
        else
          l = m + 1;
      }
    }

    return -1;
  }

  int findInMountainArray(int target, MountainArray &mountainArr) {
    int n = mountainArr.length();
    int l = 0, h = n - 1, m, ans;

    while (l < h) {
      m = (l + h) / 2;

      if (mountainArr.get(m) < mountainArr.get(m + 1))
        l = m + 1;
      else
        h = m;
    }

    ans = binSearch(0, l, target, mountainArr, true);
    if (ans != -1)
      return ans;

    return binSearch(l + 1, n - 1, target, mountainArr, false);
  }
};