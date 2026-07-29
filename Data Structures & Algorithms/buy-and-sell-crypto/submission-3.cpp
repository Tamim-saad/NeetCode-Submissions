#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int min_so_far = prices[0], max_profit = 0;
    for (auto x : prices) {
      max_profit = max(max_profit, x - min_so_far);
      min_so_far = min(min_so_far, x);
    }
    return max_profit;
  }
};