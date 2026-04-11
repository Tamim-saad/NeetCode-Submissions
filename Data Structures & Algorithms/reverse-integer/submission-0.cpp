// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int reverse(int x) {
    long ans = 0;
    int f = 0;
    if (x < 0) {
      x *= -1;
      f = 1;
    }
    if (log10(x + 1) > 9)
      return 0;
    while (x) {
      ans *= 10;
      if (ans < LONG_MIN || ans > LONG_MAX)
        return 0;
      ans += x % 10;
      x /= 10;
    }
    if (ans < LONG_MIN || ans > LONG_MAX)
      ans = 0;
    if (f)
      return ans * (-1);
    else
      return ans;
  }
};