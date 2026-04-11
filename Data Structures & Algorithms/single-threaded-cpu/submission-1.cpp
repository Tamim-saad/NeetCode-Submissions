/// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> getOrder(vector<vector<int>> &tasks) {
    int n = tasks.size();
    for (int i = 0; i < n; i++)
      tasks[i].emplace_back(i);
    sort(tasks.begin(), tasks.end());

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>>
        active;

    vector<int> ans;
    int end = 0, i = 0;

    while (i < n || !active.empty()) {
      if (i < n && end < tasks[i][0]) {
        auto x = tasks[i];
        active.push({x[1], x[0], x[2]});
        end += x[0] - end;
        i++;
      } else {
        while (i < n && end >= tasks[i][0]) {
          auto x = tasks[i];
          active.push({x[1], x[0], x[2]});
          i++;
        }
      }

      auto y = active.top();
      active.pop();
      ans.emplace_back(y[2]);
      end += y[0];
    }

    return ans;
  }
};
