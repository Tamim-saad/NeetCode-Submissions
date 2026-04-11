#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    reverse(digits.begin(), digits.end());
    int inHand = 1;
    for (int i = 0; i < digits.size(); i++) {
      if (inHand == 1) {
        if (digits[i] == 9) {
          digits[i] = 0;
          inHand = 1;
        } else {
          digits[i] += 1;
          inHand = 0;
        }
      }
    }
    if (inHand == 1) {
      digits.push_back(1);
    }
    reverse(digits.begin(), digits.end());
    return digits;
  }
};