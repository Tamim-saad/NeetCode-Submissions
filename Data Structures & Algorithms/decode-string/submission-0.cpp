#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string decodeString(string s) {
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ']') {
        string substr = "";
        while (st.top() != '[') {
          substr += st.top();
          st.pop();
        }
        st.pop();

        reverse(substr.begin(), substr.end());
        string num = "";

        while (!st.empty() && isdigit(st.top())) {
          num += st.top();
          st.pop();
        }
        reverse(num.begin(), num.end());
        int n = stoi(num);

        string temp = substr;
        for (int j = 1; j < n; j++) {
          substr += temp;
        }

        for (int j = 0; j < substr.size(); j++) {
          st.push(substr[j]);
        }

      } else {
        st.push(s[i]);
      }
    }
    string ans = "";
    while (!st.empty()) {
      ans += st.top();
      st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};