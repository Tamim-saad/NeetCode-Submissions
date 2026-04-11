// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &a, const vector<int> &b) {
           if (a[1] == b[1])
             return a[0] <= b[0];
           return a[1] <= b[1];
         });

    // for (int i = 0; i < intervals.size(); i++)
    // {
    //   cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
    // }

    vector<int> t = intervals[0];

    int i = 1, count = 1;
    while (i< intervals.size()) {
      if (t[1] <= intervals[i][0]) {
        count++;
        t = intervals[i];
      }
      i++;
    }
    return intervals.size() - count;
  }
};
