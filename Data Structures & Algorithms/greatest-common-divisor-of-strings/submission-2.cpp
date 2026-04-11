/// Alhamdulillah

#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
public:
  string gcdOfStrings(string str1, string str2) {

    string s, t, x;
    if (str1.length() <= str2.length()) {
      s = str1;
      t = str2;
    } else {
      s = str2;
      t = str1;
    }

    string ans = "";

    for (int i = 1; i <= s.length(); i++) {
      if (i == 1)
        x = s[0];
      else
        x += s[i - 1];

      int times = s.length() / x.length();

      string y = "";

      while (y.length() < s.length()) {
        y += x;
      }
      string z = y;
      while (z.length() < t.length()) {
        z += x;
      }
      if ((y == s && z == t))
        ans = x;
    }

    return ans;
  }
};