/// Alhamdulillah

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  bool carPooling(vector<vector<int>> &trips, int capacity) {
    vector<int> v(1001, 0);
    for (auto x : trips) {
      v[x[1]] += x[0];
      v[x[2]] -= x[0];
    }
    // for (int i = 0; i < 10; i++) {
    // cout << " ++++ " << v[i] << endl;
    // }
    int curr = 0; // trips[0][0];
    for (int i = 0; i <= 1000; i++) {
      curr += v[i];
      // cout << " --- " << v[i] << " --- " << curr << endl;
      if (curr > capacity)
        return false;
    }

    return true;
  }
};
