/// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> asteroidCollision(vector<int> &asteroids) {

    vector<int> ans;
    for (auto x : asteroids) {
      ans.emplace_back(x);

      while (ans.size() > 1 && ans[ans.size() - 2] > 0 && ans.back() < 0) {

        if ((ans.back() + ans[ans.size() - 2]) == 0) {
          ans.pop_back();
          ans.pop_back();
          continue;
        }

        int p = ans.back();
        ans.pop_back();
        int q = ans.back();
        ans.pop_back();

        if (abs(p) > abs(q))
          ans.emplace_back(p);
        else
          ans.emplace_back(q);
      }
    }

    return ans;
  }
};