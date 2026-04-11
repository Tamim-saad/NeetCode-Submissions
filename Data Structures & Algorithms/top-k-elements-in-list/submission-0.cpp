// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    map<int, int> mp;
    for (auto x : nums) {
      mp[x]++;
    }

    vector<int> ans;
    vector<pair<int, int>> vec(mp.begin(), mp.end());

    sort(vec.begin(), vec.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
           return a.second >= b.second;
         });
    for (int i = 0; i <k; i++)
    {
      ans.push_back(vec[i].first);
    }
      sort(ans.begin(), ans.end());
    return ans;
  }

};