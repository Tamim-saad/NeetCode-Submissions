#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
  queue<int> q1;
  int len;
  MyStack() {
    while (!q1.empty())
      q1.pop();

    len = 0;
  }

  void push(int x) {
    q1.push(x);
    len++;
  }

  int pop() {
    for (int i = 1; i < len; i++) {
      q1.push(q1.front());
      q1.pop();
    }

    int x = q1.front();
    q1.pop();
    len--;

    return x;
  }

  int top() { return q1.back(); }

  bool empty() { return q1.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */