// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
		int n=nums.size();
        int mini,maxi,ans;
        mini=maxi=ans=nums[0];
        for(int i=1;i<n;i++)
        {
            int x=nums[i];
            int t=maxi;
            maxi=max(x,max(x*mini,x*maxi));
            mini=min(min(x*mini,x),x*t);
            ans=max(ans,maxi);
            cout<<maxi<<" - "<<mini<<" + "<<ans<<endl;
        }
        return ans;
    }
};