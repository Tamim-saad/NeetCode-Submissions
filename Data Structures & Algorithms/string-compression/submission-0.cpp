#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void change(vector<char> &chars, int &ind, const string &fit) {
    for (auto x : fit)
      chars[ind++] = x;
  }

  int compress(vector<char> &chars) {
    int r = 0, w = 0;

    while (r < chars.size()) {
      int start = r;
      while (r < chars.size() && chars[start] == chars[r])
        r++;

      chars[w++] = chars[start];
      int len = r - start;

      if (len > 1)
        change(chars, w, to_string(len));
    }
    return w;
  }
};