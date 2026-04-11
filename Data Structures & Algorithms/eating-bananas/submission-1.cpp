#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mini=INT_MAX;
        int maxi= INT_MIN;
        for(auto x:piles){
            mini=min(mini,x);
            maxi=max(maxi,x);
        }
        int lowrate=1;
        int highrate=maxi;
        while(lowrate<highrate)
        {
			int rate=(lowrate+highrate)/2;
            int hour=0;
            for(auto x:piles)
            {
                hour+=ceil(( double)x/rate);
            }
            if(hour>h) 
            {
                lowrate=rate+1;
            }
            else
            {
                highrate=rate;
            }
        }
        return lowrate;
    }
};