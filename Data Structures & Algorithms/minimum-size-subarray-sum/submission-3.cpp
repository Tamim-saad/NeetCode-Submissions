#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int i, j, n, mini = INT_MAX, curr;
    n = nums.size();

    curr = i = j = 0;

    while (i < n) {
      curr += nums[i];

      while (curr >= target) {
        mini = min(mini, i - j + 1);
        curr -= nums[j++];
      }
      i++;
    }

    return (mini == INT_MAX) ? 0 : mini;
  }
};