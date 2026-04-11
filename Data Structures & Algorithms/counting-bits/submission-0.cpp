// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
      vector<int> ans;
      for (int i = 0; i <= n;i++) {
        int sum=0;
        string s = bitset<10>(i).to_string();
        // cout<<s<<endl;
        for(int j=0;j<10;j++)
        {
          if(s[j]=='1') sum++;
        }
        ans.push_back(sum);
      }
      return ans;
    }
};
