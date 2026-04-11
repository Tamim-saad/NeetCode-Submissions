#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    map<char, bool> found;
    map<char, int> lastIndex;
    int ans = 0, left = 0;
    for (int i = 0; i < s.size(); i++) {

      if (found[s[i]] == true) {
        while (s[left] != s[i])
        {
          found[s[left]]=false;
          left++;
        }
        left++;
        // cout<<"no "<<left<<" "<<right<<endl;
        ans = max(ans, i - left+1);
      } else
      {
        // cout<<"no "<<left<<" "<<right<<endl;
        ans = max(ans, i - left + 1);
        found[s[i]] = true;
      }

      // lastIndex[s[i]] = i;
      // found[s[i]] = true;
    }
    return ans;
  }
};