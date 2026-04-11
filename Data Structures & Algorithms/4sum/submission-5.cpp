#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    set<vector<int>> st;
    sort(nums.begin(), nums.end());

    int n = nums.size();

    for (auto x : nums) {
      cout << x << " ";
    }
    cout << endl;

    for (int i = 0; i < n - 3; i++) {
      for (int j = i + 1; j < n - 2; j++) {
        int a = nums[i];
        int b = nums[j];
        int l = j + 1;
        int r = n - 1;

        while (l < r) {
          if (l < r &&
              (ll)a + (ll)b + (ll)nums[l] + (ll)nums[r] == (ll)target) {

            vector<int> quad = {a, b, nums[l], nums[r]};
            sort(quad.begin(), quad.end());
            st.insert(quad);
            l++;
            r--;
          } else if (a + b + nums[l] + nums[r] > target) {
            r--;
          } else {
            l++;
          }
        }
      }
    }
    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
  }
};