#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int unSold = INT_MIN;
    int justSold = 0;
    int waitedSold = 0;

    for (auto x : prices) {
      int newUnSold = max(unSold, waitedSold - x);
      int newJustSold = max(justSold, unSold + x);
      waitedSold = max(waitedSold, justSold);

      unSold = newUnSold;
      justSold = newJustSold;
    }

    return max(justSold, waitedSold);
  }
};