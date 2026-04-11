// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    if (n == 1)
      return;
    int limit = n / 2;
    int count = n - 1;

    for (int k = 0; k < limit; k++) {
      for (int i = k; i-k < count; i++) {
        //if(i==k && n%2) continue;

        int temp = matrix[i][n-1-k];

        matrix[i][n - 1 - k] = matrix[k][i];
        matrix[k][i] = matrix[n - 1 - i][k];
        matrix[n - 1 - i][k] = matrix[n - 1 - k][n - 1 - i];
        matrix[n - 1 - k][n - 1 - i] = temp;
      }
      count -= 2;
    }
  }
};