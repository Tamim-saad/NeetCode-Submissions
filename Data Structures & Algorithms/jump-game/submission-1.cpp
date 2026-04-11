/// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool canJump(vector<int> &nums) {
		// if(nums[0] == 0) return false;

		int n=nums.size();
    vector<bool> ans(n + 1);
    ans[0] = true;

    for (int i = 0; i < n; i++) {
			int len=nums[i];
			// if(len==0) continue;
			
      for (int j = 0; j <= len; j++) {
        if (i + j <= n)
          ans[i + j] = ans[i];
      }
    }
    return ans[n-1];
  }
};