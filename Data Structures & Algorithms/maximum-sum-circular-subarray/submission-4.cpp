/// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxSubarraySumCircular(vector<int> &nums) {
    int n = nums.size(), total = 0;
    long long maxSubArr = LONG_LONG_MIN, sum, minSubArr = LONG_LONG_MAX;

    // Kadane's algorithm for max subarray
    sum = 0;
    for (int i = 0; i < n; i++) {
      sum += nums[i];
      total += nums[i];

      maxSubArr = max(maxSubArr, sum);
      sum = sum < 0 ? 0 : sum;
    }

    // Kadane's algorithm for min subarray
    sum = 0;
    for (int i = 0; i < n; i++) {
      sum += nums[i];
      minSubArr = min(minSubArr, sum);
      sum = sum > 0 ? 0 : sum;
    }

    return maxSubArr < 0 ? maxSubArr : max(total - minSubArr, maxSubArr);
  }
};
