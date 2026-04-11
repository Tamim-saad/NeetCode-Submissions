// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
        st.push(s[i]);
        continue;
      }
      if (s[i] == ')') {
        if (st.empty() || st.top() != '(')
          return false;
      } else if (s[i] == '}') {
        if (st.empty() || st.top() != '{')
          return false;
      } else if (s[i] == ']') {
        if (st.empty() || st.top() != '[')
          return false;
      }
      st.pop();
    }

    if (st.empty())
      return true;
    return false;
  }
};
