/// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lcs(string X, string Y, int m, int n, vector<vector<int>> &dp) {
    if (m == 0 || n == 0)
      return 0;
    if (X[m - 1] == Y[n - 1])
      return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);

    if (dp[m][n] != -1) {
      return dp[m][n];
    }
    return dp[m][n] = max(lcs(X, Y, m, n - 1, dp), lcs(X, Y, m - 1, n, dp));
  }
  int longestCommonSubsequence(string X, string Y) {
    int m = X.size();
    int n = Y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return lcs(X, Y, m, n, dp);
  }
};