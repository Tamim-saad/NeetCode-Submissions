/// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class FreqStack {
public:
  priority_queue<vector<int>> pq;
  unordered_map<int, int> mp;
  int ind = 0;

  FreqStack() {}

  void push(int val) { pq.push({++mp[val], ++ind, val}); }

  int pop() {
    int x = pq.top()[2];
    pq.pop();
    mp[x]--;
    return x;
  }
};