/// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string reorganizeString(string s) {
    priority_queue<pair<int, char>> pq;
    vector<int> freq(26, 0);
    int n = s.length();

    for (auto c : s) {
      int x = ++freq[c - 'a'];
    }

    for (char c = 'a'; c <= 'z'; c++) {
      if (freq[c - 'a'] > 0) {
        pq.push({freq[c - 'a'], c});
      }
    }

    string ans = "";

    while (!pq.empty()) {
      auto x = pq.top();
      pq.pop();

      if (!ans.empty() && x.second == ans.back()) {

        if (pq.empty())
          return "";

        auto y = pq.top();
        pq.pop();

        ans += y.second;
        if (--y.first > 0)
          pq.push(y);

        pq.push(x);
      } else {
        ans += x.second;

        if (--x.first > 0)
          pq.push(x);
      }
    }

    return ans;
  }
};