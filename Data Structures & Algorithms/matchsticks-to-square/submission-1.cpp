
/// Alhamdulillah
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool makesquare(vector<int> &matchsticks) {
    int n = matchsticks.size();
    int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);

    if (sum % 4)
      return false;

    sort(matchsticks.begin(), matchsticks.end());
    int len = sum / 4;
    if (matchsticks.back() > len)
      return false;

    int combination_count = 1 << n;

    vector<int> dp(combination_count, -1);
    dp[0] = 0;

    for (int combination = 0; combination < combination_count; combination++) {
      if (dp[combination] == -1)
        continue;

      for (int i = 0; i < n; i++) {
        int curr = matchsticks[i];

        if ((combination & (1 << i)) == 0) {
          if (dp[combination] + curr <= len)
            dp[combination | (1 << i)] = (dp[combination] + curr) % len;
          else
            break;
        }
      }
    }
    return dp.back() == 0;
  }
};
