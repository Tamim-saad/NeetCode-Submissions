// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int sum = 0, ans = 0;
    int s1 = 0, s2 = 0;
    for (int i = 0; i < gas.size(); i++) {
      s1 += gas[i];
      s2 += cost[i];
      sum += gas[i] - cost[i];
      if (sum < 0) {
        ans = i + 1;
        sum = 0;
      }
    }
    if (s1 < s2)
      return -1;
    else
      return ans;
  }
};
