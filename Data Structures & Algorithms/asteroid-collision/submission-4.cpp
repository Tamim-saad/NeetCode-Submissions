#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> asteroidCollision(vector<int> &asteroids) {
    vector<int> v;

    for (auto x : asteroids) {
      while (!v.empty() && v.back() > 0 && x < 0) {
        int sum = v.back() + x;

        if (sum > 0)
          x = 0;
        else if (sum < 0)
          v.pop_back();
        else {
          x = 0;
          v.pop_back();
        }
      }

      if (x)
        v.push_back(x);
    }

    return v;
  }
};