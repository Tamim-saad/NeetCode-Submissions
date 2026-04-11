// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    int l=0;
    int r=0;
    for(auto x: nums)
    {
      int t=r;
      r=max(x+l,r);
      l=t;
    }
    return r;
  }
};
