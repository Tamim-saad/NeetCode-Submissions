#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {

    int i, j, n, curr, idx;
    n = arr.size();

    i = 0;
    j = n - 1;

    while (j - i + 1 > k) {
      if (abs(arr[i] - x) > abs(arr[j] - x)) {
        i++;
      } else {
        j--;
      }
    }

    vector<int> ans;
    for (i = i; i <= j; i++)
      ans.emplace_back(arr[i]);

    return ans;
  }
};