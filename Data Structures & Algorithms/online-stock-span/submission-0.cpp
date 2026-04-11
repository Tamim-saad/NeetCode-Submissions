#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
  stack<pair<int, int>> st;
  StockSpanner() {}

  int next(int price) {
    if (st.empty() || st.top().first > price) {
      st.push({price, 1});
      return 1;
    }
    int cnt = 1;
    while (!st.empty() && st.top().first <= price) {
      auto x = st.top();
      st.pop();
      cnt += x.second;
    }
    st.push({price, cnt});
    return cnt;
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */