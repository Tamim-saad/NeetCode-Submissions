/// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

bool compare(const vector<int> &a, const vector<int> &b) { return a[2] > b[2]; }

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    priority_queue<vector<int>, vector<vector<int>>,
                   function<bool(const vector<int> &, const vector<int> &)>>
        pq(compare);

    for (auto &x : points) {
      int t = x[0] * x[0] + x[1] * x[1];
      pq.push({x[0], x[1], t});
    }

    vector<vector<int>> ans;
    for (int i = 0; i < k; i++) {
      vector<int> x = pq.top();
      pq.pop();
      ans.push_back({x[0], x[1]});
    }
    return ans;
  }
};
