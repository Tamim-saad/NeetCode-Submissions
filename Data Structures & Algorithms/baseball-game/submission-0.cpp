/// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int calPoints(vector<string> &operations) {
    string s, t, x;
    stack<int> st;

    for (auto x : operations) {
      if (x == "+") {
        int t1 = st.top();
        st.pop();
        int t2 = st.top();
        st.push(t1);
        st.push(t1 + t2);
      } else if (x == "D") {
        st.push(2 * st.top());
      } else if (x == "C") {
        st.pop();
      } else {
        st.push(stoi(x));
      }
    }

    int ans = 0;
    while (!st.empty()) {
      ans += st.top();
      st.pop();
    }
    return ans;
  }
};
