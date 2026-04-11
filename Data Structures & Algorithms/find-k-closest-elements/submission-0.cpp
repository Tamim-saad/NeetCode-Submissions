#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {

    int i, j, n, curr, idx;
    n = arr.size();

    vector<int> ans;

    i = 0;
    j = n - 1;

    while (j - i + 1 > k) {
      if (abs(arr[i] - x) > abs(arr[j] - x)) {
        i++;
      } else {
        j--;
      }
    }

    // cout << i << " -- " << j << endl;

    for (i = i; i <= j; i++) {
      ans.emplace_back(arr[i]);
    }

    return ans;
  }
};
