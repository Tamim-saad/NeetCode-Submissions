/// Alhamdulillah

#include <algorithm>
#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
public:
  string simplifyPath(string path) {
    int n = path.size(), inc, dec, maxi = 1, cnt = 0;
    string ans = "", s = "", t = "";
    stack<string> st;

    // cout << path << endl;

    for (int i = 0; i <= n; i++) {
      char x = i < n ? path[i] : '/';

      if (x != '/') {
        t += x;
        if (x == '.')
          cnt++;
        else
          cnt = 0;
      } else {
        // cout << cnt << " --- \n";
        if (t.length() == 1 && cnt == 1) {

        } else if (cnt == 2 && t.length() == 2) {
          if (!st.empty())
            st.pop();
        } else if (t.length()) {
          st.push(t);
          // cout << t << endl;
        }
        t = "";
        s = "";
        cnt = 0;
      }
    }
    vector<string> v;
    while (!st.empty()) {
      v.emplace_back(st.top());
      st.pop();
    }
    if (v.size() == 0)
      return "/";

    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
      // cout << v[i] << " -- \n";
      ans += "/";
      ans += v[i];
    }

    return ans;
  }
};
