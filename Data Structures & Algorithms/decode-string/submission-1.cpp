#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string recur(string s, int &i) {
    string ans = "";
    int k = 0;

    while (i < s.size()) {
      if (isdigit(s[i]))
        k = k * 10 + (s[i] - '0');
      else {
        if (s[i] == '[') {
          i++;
          string substr = recur(s, i);
          for (int i = 0; i < k; i++)
            ans += substr;
          k = 0;
        } else if (s[i] == ']')
          return ans;
        else
          ans += s[i];
      }
      i++;
    }

    return ans;
  }
  string decodeString(string s) {
    int i = 0;
    return recur(s, i);
  }
};