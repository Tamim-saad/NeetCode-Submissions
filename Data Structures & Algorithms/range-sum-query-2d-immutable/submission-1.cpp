/// Alhamdulillah
#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
public:
  vector<vector<int>> preSum;
  NumMatrix(vector<vector<int>> &matrix) {
    preSum = matrix;

    for (int i = 0; i < preSum.size(); i++) {
      for (int j = 0; j < preSum[0].size(); j++) {
        cout << preSum[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;

    for (int i = 0; i < preSum.size(); i++) {
      for (int j = 1; j < preSum[0].size(); j++) {
        preSum[i][j] += preSum[i][j - 1];
        cout << preSum[i][j] << " ";
      }
    }

    for (int i = 1; i < preSum.size(); i++) {
      for (int j = 0; j < preSum[0].size(); j++) {
        preSum[i][j] += preSum[i - 1][j];
      }
    }

    for (int i = 0; i < preSum.size(); i++) {
      for (int j = 0; j < preSum[0].size(); j++) {
        cout << preSum[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  // row1 = 1
  // col = 1
  // row2 = 2
  // co2 = 2

  int sumRegion(int row1, int col1, int row2, int col2) {
    int ans = preSum[row2][col2]; // 21
    if (row1) {
      ans -= preSum[row1 - 1][col2]; // 21 -4 = 17
    }
    if (col1) {
      ans -= preSum[row2][col1 - 1]; // 17 - 9 = 8
    }
    if (row1 && col1) {
      ans += preSum[row1 - 1][col1 - 1]; // 8 + 3 = 11
    }
    return ans;
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */