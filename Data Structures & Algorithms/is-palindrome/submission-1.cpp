// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    int i = 0;
    int j = s.size() - 1;
    int n = s.size() - 1;

    for (char &c : s) {
      c = tolower(c);
    }

    while (i <= j) {
      if (!((48 <= s[i] && s[i] <= 57) || (65 <= s[i] && s[i] <= 90) ||
            (97 <= s[i] && s[i] <= 122))) {
        i++;
        continue;
      }
      if (!((48 <= s[j] && s[j] <= 57) || (65 <= s[j] && s[j] <= 90) ||
            (97 <= s[j] && s[j] <= 122))) {
        j--;
        continue;
      }

      if (s[i] != s[j])
        return false;

      i++;
      j--;
    }
    return true;
  }
};