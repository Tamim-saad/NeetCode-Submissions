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
    long time = 0, i = 0;

    while (i < n || !pq.empty()) {
      if (pq.empty())
        time = max(time, (long)tasks[i][0]);

      while (i < n && tasks[i][0] <= time) {
        pq.push({tasks[i][1], tasks[i][2]});
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
