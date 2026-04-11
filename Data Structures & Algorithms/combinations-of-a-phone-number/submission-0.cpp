// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string dig) {
    string s[] = {"",    "",    "abc",  "def", "ghi",
                  "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> ans, temp1, temp2, temp3, temp4;
    string x = "", s1 = "", s2 = "", s3 = "", s4 = "";

    int k = dig.size();

    if (k >= 1)
      s1 = s[dig[0] - '0'];
    if (k >= 2)
      s2 = s[dig[1] - '0'];
    if (k >= 3)
      s3 = s[dig[2] - '0'];
    if (k >= 4)
      s4 = s[dig[3] - '0'];

    for (int i1 = 0; i1 < s1.size() && k >= 1; i1++) {
      x = s1[i1];
      temp1.push_back(x);
    }
    if (k - 1 == 0)
      return temp1;

    for (int i2 = 0; i2 < s2.size() && k >= 2; i2++) {
      for (auto z : temp1) {
        x = z + s2[i2];
        temp2.push_back(x);
      }
    }
    if (k - 2 == 0)
      return temp2;

    for (int i3 = 0; i3 < s3.size() && k >= 3; i3++) {
      for (auto z : temp2) {
        x = z + s3[i3];
        temp3.push_back(x);
      }
    }
    if (k - 3 == 0)
      return temp3;

    for (int i4 = 0; i4 < s4.size() && k >= 4; i4++) {
      for (auto z : temp3) {
        x = z + s4[i4];
        temp4.push_back(x);
      }
    }

    if (k - 4 == 0)
      return temp4;
    return ans;
  }
};
