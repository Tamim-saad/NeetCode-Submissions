#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    map<int, int> mp;
    for (auto x : nums) {
      if (mp[x] == 1) {
        return x;
      } else {
        mp[x] = 1;
      }
    }
    return 0;
  }
};
