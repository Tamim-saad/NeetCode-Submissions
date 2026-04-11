// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    vector<int> rows, cols;
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          rows.push_back(i);
          cols.push_back(j);
        }
      }
    }

    sort(rows.begin(), rows.end());
    sort(cols.begin(), cols.end());

    for (int i = 0; i < rows.size(); i++) {
      int t = rows[i];
      for (int j = 0; j < n; j++) {
        matrix[t][j] = 0;
      }
    }
    for (int i = 0; i < cols.size(); i++) {
      int t = cols[i];
      for (int j = 0; j < m; j++) {
        matrix[j][t] = 0;
      }
    }
    // return matrix;
  }
};
