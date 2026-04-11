// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &a, const vector<int> &b) {
           if (a[0] == b[0])
             return a[1] <= b[1];
           return a[0] <= b[0];
         });

    for (int i = 0; i < intervals.size(); i++)
    {
      cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
    }

    vector<vector<int>> vans;
    vans.push_back({intervals[0][0], intervals[0][1]});

    int i = 1;
    while (i < intervals.size()) {
      if (vans[vans.size()-1][1] >= intervals[i][0]) {
        vans[vans.size()-1][1]=max(vans[vans.size()-1][1],intervals[i][1]);
      }
      else
      {
        vans.push_back({intervals[i][0],intervals[i][1]});
      }
      i++;
    }

    return vans;
    // return intervals;
  }
};