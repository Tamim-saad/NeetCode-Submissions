#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    vector<int> ans;
    int l = 0, r = arr.size() - 1;
    while (r - l + 1 > k) {
      if (abs(arr[l] - x) <= abs(arr[r] - x))
        r--;
      else
        l++;
    }
    while (l <= r)
      ans.push_back(arr[l++]);

    return ans;
  }
};