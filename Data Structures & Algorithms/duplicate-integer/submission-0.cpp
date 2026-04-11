// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
      map<int,bool> mp;
      for(auto x: nums)
      {
        if(mp[x] == true) return true;
        mp[x]=true;
      }
      return false;
    }
};