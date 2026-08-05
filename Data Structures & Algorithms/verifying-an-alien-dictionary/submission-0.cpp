#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  map<char, int> mp;
  int check(string a, string b) {
    int i = 0;
    while (i < min(a.size(), b.size())) {
      if (a[i] != b[i]) {
        if (mp[a[i]] > mp[b[i]])
          return false;
        else
          return true;
      }
      i++;
    }
    return a.size() <= b.size();
  }

  bool isAlienSorted(vector<string> &words, string order) {
    for (int i = 0; i < order.size(); i++)
      mp[order[i]] = i;

    for (int i = 0; i < words.size() - 1; i++) {
      for (int j = i + 1; j < words.size(); j++) {
        if (!check(words[i], words[j]))
          return false;
      }
    }

    return true;
  }
};