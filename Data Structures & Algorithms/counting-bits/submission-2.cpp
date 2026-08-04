#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> v;
    int ans;

    for (int i = 0; i <= n; i++) {
      int ans = 0;
      int x = i;
      while (x) {
        ans += x & 1;
        x >>= 1;
      }

      v.emplace_back(ans);
    }
    return v;
  }
};
