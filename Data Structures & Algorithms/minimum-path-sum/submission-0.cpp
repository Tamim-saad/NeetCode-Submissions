/// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    // vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
    vector<vector<int>> dp = grid;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {

        if (!i && !j) {
          // dp[i][j] = grid[i][j];
          continue;
        }
        if (!i) {
          dp[i][j] += dp[i][j - 1];
          continue;
        }
        if (!j) {
          dp[i][j] += dp[i - 1][j];
          continue;
        }

        dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);

        cout << dp[i][j] << " ";
      }
      cout << endl;
    }

    return dp[m - 1][n - 1];
  }
};