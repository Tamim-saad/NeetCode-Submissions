#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    vector<int> vc;
    set<int> st(nums.begin(), nums.end());
    int ans = 0, length=0;
    for (auto i = st.begin(); i != st.end(); i++) {
      if (i == st.begin() || *i != *prev(i) + 1) {
        ans = max(ans, length);
        length = 1;
      } else {
        length++;
      }
    }
    return max(length,ans);
  }
};