// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_multiset;

class Solution {
public:
  int carFleet(int target, vector<int> &position, vector<int> &speed) {
    indexed_multiset ms;
    for (int i = 0; i < position.size(); i++) {
      ms.insert({position[i], speed[i]});
    }
    int ans = 1;
    pair<int, int> pr;
    double last;
    pr = *(--ms.end());
    last = (target - pr.first) / (float)pr.second;
    ms.erase(--ms.end());
    while (!ms.empty()) {
      pr = *(--ms.end());
      ms.erase(--ms.end());
      double time = (target - pr.first) / (float)pr.second;
      if (time > last) {
        ans++;
        last = time;
      }
    }
    return ans;
  }
};