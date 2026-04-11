// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
  int sumSquareDigit(int n) {
    int ans = 0;
    while (n) {
      ans += (n % 10) * (n % 10);
      n /= 10;
    }
    return ans;
  }

public:
  bool isHappy(int n) {
    int slow = n;
    int fast = sumSquareDigit(n);
    while (slow != fast) {
      slow = sumSquareDigit(slow);
      fast = sumSquareDigit(fast);
      fast = sumSquareDigit(fast);
    }
    return fast == 1;
  }
};

// int main() { cout << isHappy(100); }