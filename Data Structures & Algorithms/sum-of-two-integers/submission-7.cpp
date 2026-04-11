#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int getSum(int a, int b) {
    if (!a || !b)
      return a | b;

    return getSum(a ^ b, (a & b) << 1);
  }
};