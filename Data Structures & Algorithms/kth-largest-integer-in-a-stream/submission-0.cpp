#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
  priority_queue<int> pq;
  int x,y;
  KthLargest(int k, vector<int> &nums) {
    for (auto x : nums) {
      pq.push(x);
    }
    x=k;
  }

  int add(int val) {
    pq.push(val);
    priority_queue<int> pq2 = pq;
    y = x;
    while (y>1) {
      pq2.pop();
      y--;
    }
    return pq2.top();
  }
};
