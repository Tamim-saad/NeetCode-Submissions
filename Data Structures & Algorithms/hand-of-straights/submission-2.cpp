// say Alhamdulillah

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_multiset;

class Solution {
public:
  bool isNStraightHand(vector<int> &hand, int k) {
    if (hand.size() % k)
      return false;

    indexed_multiset ms;
    int idx = 0;

    for (auto x : hand) {
      ms.insert({x, idx++});
    }

    for (int i = 0; i < hand.size() / k; i++) {
      auto it = ms.begin();
      for (int j = 0; j < k; j++) {
        int x = it->first;
        int y = it->second;

        ms.erase(it);
        if (j == k - 1)
          break;

        it = ms.lower_bound({x + 1, -1});
        if (it == ms.end() || it->first - x != 1) {
          return false;
        }
      }
    }
    return true;
  }
};