/// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int guessNumber(int n) {
    long h, l, mid;
    h = n;
    l = 1;

    while (l < h) {
      mid = (l + h) / 2;
      if (guess(mid) == 1) {
        l = mid + 1;
      } else if (guess(mid) == -1) {
        h = mid - 1;
      } else
        return (int)mid;
    }

    return (int)l;
  }
};