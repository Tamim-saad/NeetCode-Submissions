// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> st;
    for (auto x : tokens) {
      if (x == "*" || x == "+" || x == "-" || x == "/") {
        int n2 = st.top();
        st.pop();
        int n1 = st.top();
        st.pop();
        if (x == "+")
          st.push(n1 + n2);
        if (x == "-")
          st.push(n1 - n2);
        if (x == "*")
          st.push(n1 * n2);
        if (x == "/")
          st.push(int(n1 / n2));
      } else
        st.push(stoi(x));
    }
    return st.top();
  }
};
