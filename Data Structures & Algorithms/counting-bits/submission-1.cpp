#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> v;
    int ans;

    for (int i = 0; i <= n; i++) {
      ans = 0;
      string curr = bitset<20>(i).to_string();

      for (int j = 0; j < curr.size(); j++)
        ans += (curr[j] - '0') & 1;

      v.emplace_back(ans);
    }
    return v;
  }
};
