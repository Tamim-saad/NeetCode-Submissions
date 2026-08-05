#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long minEnd(int n, int x) {

    long long numberToInsert = n - 1, reader = 1, finder = 1, ans = x;

    while (reader <= numberToInsert) {
      while (ans & finder)
        finder <<= 1;

      if (numberToInsert & reader)
        ans |= finder;

      finder <<= 1;
      reader <<= 1;
    }

    return ans;
  }
};