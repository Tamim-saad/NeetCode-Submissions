/// Alhamdulillah

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {

    priority_queue<pair<int, char>> pq;
    vector<int> freq(26, 0), last(26, -(n + 1));

    for (auto c : tasks)
      freq[c - 'A']++;

    for (char c = 'A'; c <= 'Z'; c++) {
      if (freq[c - 'A'] > 0)
        pq.push({freq[c - 'A'], c});
    }

    int i = 0;
    string ans = "";

    while (!pq.empty()) {
      vector<pair<int, char>> checked;

      while (!pq.empty() && i - last[pq.top().second - 'A'] <= n) {
        auto x = pq.top();
        pq.pop();
        checked.emplace_back(x);
      }

      if (pq.empty()) {
        ans += 'i';
      } else {
        auto y = pq.top();
        pq.pop();

        ans += y.second;
        last[y.second - 'A'] = i;
        if (--y.first > 0)
          pq.push(y);
      }
      for (auto z : checked)
        pq.push(z);

      i++;
    }

    cout << ans << endl;
    return ans.length();
  }
};
