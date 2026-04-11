/// Alhamdulillah

#include <bits/stdc++.h>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
  string longestDiverseString(int a, int b, int c) {
    priority_queue<pair<int, char>> pq;
    if (a)
      pq.push({a, 'a'});
    if (b)
      pq.push({b, 'b'});
    if (c)
      pq.push({c, 'c'});

    string ans = "";
    char last2 = 'd';

    while (!pq.empty()) {
      auto x = pq.top();
      pq.pop();

      if (ans.length() >= 2 && x.second == ans.back() &&
          x.second == ans[ans.length() - 2]) {

        if (pq.empty()) {
          return ans;
        }

        auto y = pq.top();
        pq.pop();
        ans += y.second;
        if (y.first - 1 > 0)
          pq.push({y.first - 1, y.second});
        pq.push(x);
      } else {
        ans += x.second;
        if (x.first - 1 > 0)
          pq.push({x.first - 1, x.second});
      }
    }

    return ans;
  }
};