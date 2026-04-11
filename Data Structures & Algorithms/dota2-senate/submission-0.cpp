/// Alhamdulillah

#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
  string predictPartyVictory(string senate) {
    int r = 0, d = 0, w = 0, remD = 0, remR = 0;
    for (auto x : senate) {
      if (x == 'R')
        remR++;
      if (x == 'D')
        remD++;
    }
    int n = senate.size();

    for (int i = 0; i <= INT_MAX; i++) {

      // cout << r << " " << d << " " << remR << " " << remD << endl;
      if (remR == 0 || (remR * 2 <= remD)) {
        return "Dire";
      }
      if (remD == 0 || (remD * 2 <= remR)) {
        return "Radiant";
      }
      if (senate[i % n] == 'R') {
        if (r < 0) {
          senate[i % n] = 'Z';
          r++;
        } else {
          remD--;
          d--;
        }
      } else if (senate[i % n] == 'D') {
        if (d < 0) {
          senate[i % n] = 'Z';
          d++;
        } else {
          remR--;
          r--;
        }
      }
    }

    return "";
  }
};
