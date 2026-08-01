#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {

    vector<int> firstCol;
    for (int i = 0; i < matrix.size(); i++)
      firstCol.emplace_back(matrix[i][0]);

    auto it = upper_bound(firstCol.begin(), firstCol.end(), target) -
              firstCol.begin() - 1;
    if (it < 0)
      return false;

    auto x = lower_bound(matrix[it].begin(), matrix[it].end(), target);
    if (matrix[it].end() != x && *x == target)
      return true;

    return false;
  }
};
