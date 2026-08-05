#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool recur(int start, vector<int> sides, int &len, vector<int> &matchsticks) {
    if (start >= matchsticks.size())
      return true;

    for (int i = 0; i < 4; i++) {
      if (sides[i] + matchsticks[start] <= len) {

        sides[i] += matchsticks[start];
        if (recur(start + 1, sides, len, matchsticks))
          return true;

        sides[i] -= matchsticks[start];
      }

      if (sides[i] == 0)
        break;
    }

    return false;
  }

  bool makesquare(vector<int> &matchsticks) {
    int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if (sum % 4)
      return false;
    vector<int> sides(4, 0);
    sum /= 4;
    sort(matchsticks.rbegin(), matchsticks.rend());

    return recur(0, sides, sum, matchsticks);
  }
};