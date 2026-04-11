// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int recur(int a, int b)
  {
    if(!a || !b) return a|b;
    return recur(a^b, (a&b)<<1);
  }

  int getSum(int a, int b) {
    return recur(a, b);
  }
};