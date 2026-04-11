// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t ans;

    for (int i = 31; i >= 0; i--) {
      if (n & 1) {
        ans += 1 << i;
      }
      n >>= 1;
    }

    // cout << ans;
    return ans;
  }
};
