// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

// class Interval {
// public:
//   int start, end;
//   Interval(int start, int end) {
//     this->start = start;
//     this->end = end;
//   }
// };

class Solution {
public:
  int minMeetingRooms(vector<Interval> &intervals) {
    return countDay(intervals);
  }
  int countDay(vector<Interval> &intervals) {
    if (intervals.size() == 0)
      return 0;
    sort(intervals.begin(), intervals.end(),
         [](const Interval &a, const Interval &b) {
           if (a.end == b.end)
           if(a.end==b.end)
             return a.start <= b.start;
           return a.end <= b.end;
         });

    // for (int i = 0; i < intervals.size(); i++)
    // {
    //   cout<<intervals[i].start<<" "<<intervals[i].end<<endl;
    // }

    Interval t = intervals[0];
    vector<Interval> temp;

    int i = 1, count = 1;
    while (i < intervals.size()) {
      if (t.end <= intervals[i].start) {
        // count++;
        t = intervals[i];
      } else {
        temp.push_back(intervals[i]);
      }
      i++;
    }

    return 1 + countDay(temp);
  }
};
