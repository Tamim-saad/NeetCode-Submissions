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

    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>>
        pq;

    vector<int> ans;
    int time = 0, i = 0;

    while (i < n || !pq.empty()) {
      if (i < n && time < tasks[i][0]) {
        time = tasks[i][0];
      }

      while (i < n && tasks[i][0] <= time) {
        auto x = tasks[i];
        pq.push({x[1], x[2]});
        i++;
      }

      auto y = pq.top();
      pq.pop();
      ans.emplace_back(y[1]);
      time += y[0];
    }

    return ans;
  }
};
