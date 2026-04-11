// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
      map<char,int> mp,mp2;
      for(char c : s){
        mp[c-'a']++;
      }
      for(char c : t){
        mp2[c-'a']++;
      }
      for(int i=0;i<26;i++)
      {
        if(mp[i]!=mp2[i]) return false;
      }
      return true;
        
    }
};