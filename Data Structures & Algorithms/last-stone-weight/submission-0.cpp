/// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lastStoneWeight(vector<int> &stones) {
    priority_queue<int> pq, pq1, pq2;
    for (auto x : stones) {
      pq.push(x);
    }
    while (pq.size() > 1) {
      int p = pq.top();
      pq.pop();
      int q = pq.top();
      pq.pop();
      pq.push(max(p, q) - min(p, q));
    }
    if (pq.size() == 0)
      return 0;
    else
      return pq.top();
  }
};
