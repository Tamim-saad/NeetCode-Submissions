// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    for (int i = 0; i < numbers.size() - 1; i++) {
      auto it = lower_bound(numbers.begin() + i + 1, numbers.end(),
                            target - numbers[i]);
      if (it != numbers.end() && *it == target - numbers[i]) {
        return {i + 1, it - numbers.begin() + 1};
      }
    //   return {};
    }
  }
};