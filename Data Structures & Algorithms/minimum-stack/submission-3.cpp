#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
  int mini;
  stack<long> st;
  MinStack() {}

  void push(int val) {
    if (st.empty()) {
      mini = val;
      st.push(0);
    } else {
      st.push(val - mini);
      if (val < mini)
        mini = val;
    }
  }

  void pop() {
    if (st.empty())
      return;
    auto x = st.top();
    st.pop();
    if (x < 0)
      mini = mini - x;
  }

  int top() {
    auto x = st.top();
    return x < 0 ? mini : mini + x;
  }

  int getMin() { return mini; }
};
