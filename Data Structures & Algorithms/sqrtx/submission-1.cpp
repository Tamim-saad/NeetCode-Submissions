#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int mySqrt(int x) {
    long long l = 1;
    long long h = x;

    while (l <= h) {
      long long mid = (l + h) / 2;
      if (mid * mid > x) {
        h = mid - 1;
      } else if (mid * mid < x) {
        l = mid + 1;
      } else
        return mid;
    }
    return l - 1;
  }
};