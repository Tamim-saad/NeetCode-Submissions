#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
      string ans="";
      for(auto x: strs)
      {
        string size=to_string(x.size());
        string len=to_string(size.size());
        ans+=len+size+x;
      }
      return ans;
    }

    vector<string> decode(string s) {
      vector<string> ans;
      int i=0;
      while(i<s.size())
      {
        int len=s[i]-'0';
        int size=stoi(s.substr(i+1,len));
        i+=len;
        string t=s.substr(i+1,size);
        ans.push_back(t);
        i+=size+1;
        // cout<<len<<endl;
      }
      // vector<int> positions;

      // for(int i=0;i<s.size();i++)
      //   if(s[i]=='#') positions.push_back(i);

      // for(int i=0;i<positions.size()-1;i++)
      // {
      //   int l,r;
      //   l=positions[i];
      //   r=positions[i+1];
      // }
      return ans;

    }
};