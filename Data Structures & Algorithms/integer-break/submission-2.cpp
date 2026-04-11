/// Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int integerBreak(int n) {
    if (n == 2)
      return 1;
    if (n == 3)
      return 2;
    
    int prod = 1;
    while (n % 3 != 0) {
      prod *= 2;
      n -= 2;
    }
    int power = n / 3;
    for (int i = 0; i < power; i++) {
      prod *= 3;
    }
    return prod;
  }
};