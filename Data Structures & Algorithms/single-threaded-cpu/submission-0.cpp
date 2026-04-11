/// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> getOrder(vector<vector<int>> &tasks) {
    for (int i = 0; i < tasks.size(); i++) {
      tasks[i].emplace_back(i);
    }

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>>
        active, pq;

    vector<int> ans;
    for (auto x : tasks) {
      pq.push({x[0], x[1], x[2]}); // Convert vector<int> to array<int, 3>
    }

    int end = 0;

    for (auto x : tasks) {

      if (!pq.empty() && end < pq.top()[0]) {
        auto x = pq.top();
        pq.pop();
        active.push({x[1], x[0], x[2]});
        end += x[0] - end;
      } else {

        while (!pq.empty() && end >= pq.top()[0]) {
          auto x = pq.top();
          pq.pop();
          active.push({x[1], x[0], x[2]});
          // curr+=x[1];
        }
      }

      auto y = active.top();
      active.pop();
      ans.emplace_back(y[2]);
      end += y[0];
    }
    while (!active.empty()) {
      auto y = active.top();
      active.pop();
      ans.emplace_back(y[2]);
    }

    return ans;
  }
};
