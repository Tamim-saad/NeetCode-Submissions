/// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxTurbulenceSize(vector<int> &arr) {
    int n = arr.size(), inc = 0, dec = 0, maxi = 1;
    if (n == 1)
      return 1;

    for (int i = 0; i < n; i++) {
      if (arr[i - 1] < arr[i]) {
        inc = dec + 1;
        dec = 1;
      } else if (arr[i - 1] > arr[i]) {
        dec = inc + 1;
        inc = 1;
      } else {
        inc = dec = 1;
      }
      maxi = max(maxi, max(inc, dec));
    }

    return maxi;
  }
};