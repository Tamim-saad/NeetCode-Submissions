#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numRescueBoats(vector<int> &people, int limit) {

    int i, j, n, ans = 0, idx;
    n = people.size();

    sort(people.begin(),people.end());

    i = 0;
    j = n - 1;

    while (j >= i) {
      if (i==j || people[i] + people[j] <= limit) {
        i++;
        j--;
      } else {
        j--;
      }
      ans++;
    }

    return ans;
  }
};