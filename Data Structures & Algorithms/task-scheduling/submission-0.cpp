/// Alhamdulillah

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {

    priority_queue<pair<int, char>> pq;
    vector<int> freq(26, 0), last(26, -(n + 1));

    for (auto c : tasks) {
      // int x =
      freq[c - 'A']++;
      // if(x)
    }

    // cout << " --- \n";
    for (char c = 'A'; c <= 'Z'; c++) {
      if (freq[c - 'A'] > 0) {
        pq.push({freq[c - 'A'], c});
      }
    }

    int gap = n, val, i = 0;
    string ans = "";

    while (!pq.empty()) {
      vector<pair<int, char>> checked;

      while (!pq.empty() && i - last[pq.top().second - 'A'] <= n) {
        auto y = pq.top();
        pq.pop();
        checked.emplace_back(y);
      }

      if (pq.empty()) {
        ans += "i";
        i++;
      } else {

        auto z = pq.top();
        pq.pop();

        ans += z.second;
        last[z.second - 'A'] = i;
        if (--z.first > 0)
          pq.push(z);
        i++;
      }
      for (auto t : checked) {
        pq.push(t);
      }
    }

    cout << ans << endl;
    return ans.length();
  }
};