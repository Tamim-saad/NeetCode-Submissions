#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
  vector<int> v;
  MedianFinder() {}

  void addNum(int num) {
    if (v.empty())
      v.push_back(num);
    else {
      v.insert(upper_bound(v.begin(), v.end(), num), num);
    }
  }

  double findMedian() {
    int n = v.size();
    int a = v[n / 2];
    int b = a;
    if (n % 2 == 0) {
      b = v[n / 2 - 1];
    }
    return (a + b) / 2.0;
  }
};