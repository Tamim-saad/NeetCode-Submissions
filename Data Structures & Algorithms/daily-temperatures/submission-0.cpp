// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    stack<int> st;
    vector<int> ans;
    for (int i = temperatures.size() - 1; i >= 0; i--) {
      if (st.empty()) {
        ans.push_back(0);
        st.push(i);
      } else if (temperatures[i] >= temperatures[st.top()]) {
        while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
          st.pop();
        }
        if (!st.empty())
          ans.push_back(st.top() - i);
        else
          ans.push_back(0);
        st.push(i);
      } else {
        ans.push_back(1);
        st.push(i);
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
