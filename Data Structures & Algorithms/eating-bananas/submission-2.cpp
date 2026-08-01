#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for (auto x : piles) {
      mini = min(mini, x);
      maxi = max(maxi, x);
    }

    int lr = 1;
    int hr = maxi;

    while (lr < hr) {
      int rate = (lr + hr) / 2;

      int hour = 0;
      for (auto x : piles)
        hour += ceil((double)x / rate);

      if (hour > h)
        lr = rate + 1;
      else
        hr = rate;
    }
    return lr;
  }
};