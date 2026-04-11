#include <bits/stdc++.h>
#include <stack>
using namespace std;

class MyQueue {
public:
  stack<int> st, st2;
  int len;
  MyQueue() {
    len = 0;
    while (!st.empty()) {
      st.pop();
    }
  }

  void push(int x) {
    while (!st.empty()) {
      st2.push(st.top());
      st.pop();
    }
    st.push(x);
    len++;
    while (!st2.empty()) {
      st.push(st2.top());
      st2.pop();
    }
  }

  int pop() {
    int x = st.top();
    st.pop();
    len--;
    return x;
  }

  int peek() { return st.top(); }

  bool empty() { return len <= 0; }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */