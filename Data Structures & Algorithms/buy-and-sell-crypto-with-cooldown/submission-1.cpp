#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int buy = INT_MIN;
    int justSold = 0;
    int waitedSold = 0;

    for (auto x : prices) {
      int newBuy = max(buy, waitedSold - x);
      int newJustSold = max(justSold, buy + x);
      waitedSold = max(waitedSold, justSold);

      buy = newBuy;
      justSold = newJustSold;
    }

    return max(justSold, waitedSold);
  }
};