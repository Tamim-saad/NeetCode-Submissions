#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.size() < nums2.size())
      swap(nums1, nums2);

    int n1 = nums1.size();
    int n2 = nums2.size();
    int n = n1 + n2;

    int l = 0, r = n2;
    while (l <= r) {
      int mid = (l + r) / 2;
      int ind = (n + 1) / 2 - mid;

      int l1 = ind == 0 ? INT_MIN : nums1[ind - 1];
      int r1 = ind == n1 ? INT_MAX : nums1[ind];
      int l2 = mid == 0 ? INT_MIN : nums2[mid - 1];
      int r2 = mid == n2 ? INT_MAX : nums2[mid];

      if (max(l1, l2) <= min(r1, r2)) {
        if (n % 2)
          return max(l1, l2);
        return (max(l1, l2) + min(r1, r2)) / 2.0;
      }

      if (l2 > r1)
        r = mid - 1;
      else
        l = mid + 1;
    }

    return 0;
  }
};