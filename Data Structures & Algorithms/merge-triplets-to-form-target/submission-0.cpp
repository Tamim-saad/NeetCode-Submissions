// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target) {
    bool f1, f2, f0;
    f1 = f2 = f0 = false;
    for (auto it = triplets.begin(); it != triplets.end();) {
      vector<int> &x = *it;
      if (x[0] > target[0] || x[1] > target[1] || x[2] > target[2]) {
        it = triplets.erase(it);
        continue;
      } else {
        if (x[0] == target[0])
          f0 = true;
        if (x[1] == target[1])
          f1 = true;
        if (x[2] == target[2])
          f2 = true;

        it++;
      }
    }

    return f1 && f2 && f0;
  }
};
