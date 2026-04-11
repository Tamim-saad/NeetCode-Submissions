/// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
			vector<int> ans(n+1);
			ans[0]=1;


			for (int i=0; i<=n; i++)
			{
				for (int j=1; j<=2;j++)
				{
					if(i+j<=n) ans[i+j]+=ans[i];
				}
			}
			return ans[n];
        
    }
};
