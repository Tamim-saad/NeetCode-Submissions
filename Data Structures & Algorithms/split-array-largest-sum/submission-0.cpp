#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> prefix;
  int n;

  bool canSplit(vector<int> &nums, int k, int sum) {
    int i = 0;
    int divisn = 0;

    while (i < n) {
      int l = i + 1, r = n;

      while (l <= r) {
        int mid = (l + r) / 2;
        if (prefix[mid] - prefix[i] <= sum)
          l = mid + 1;
        else
          r = mid - 1;
      }
      i = r;

      divisn++;
      if (divisn > k)
        return false;
    }
    return true;
  }

  int splitArray(vector<int> &nums, int k) {
    n = nums.size();
    prefix.resize(n + 1, 0);

    for (int i = 0; i < n; i++) {
      prefix[i + 1] = prefix[i] + nums[i];
    }

    int l = *max_element(nums.begin(), nums.end());
    int r = accumulate(nums.begin(), nums.end(), 0);
    int ans = r;

    while (l <= r) {
      int mid = (l + r) / 2;
      if (canSplit(nums, k, mid)) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return ans;
  }
};