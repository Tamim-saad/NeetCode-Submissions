#include <bits/stdc++.h>
#include <cctype>
using namespace std;

class Solution {
public:
  bool alphaNum(char c) {
    return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') ||
           ('0' <= c && c <= '9');
  }

  bool isPalindrome(string s) {
    int i = 0;
    int j = s.size() - 1;

    while (i < j) {
      while (i < j && !alphaNum(s[i]))
        i++;
      while (i < j && !alphaNum(s[j]))
        j--;

      if (tolower(s[i]) != tolower(s[j]))
        return false;
      i++;
      j--;
    }
    return true;
  }
};
