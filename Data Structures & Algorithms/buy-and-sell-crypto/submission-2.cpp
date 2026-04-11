// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_so_far=prices[0],max_profit=0;
        for(int i=1;i<prices.size();i++) {
            if(prices[i]<min_so_far)
            {
                min_so_far=prices[i];
            }
            else
            {
                max_profit=max(max_profit,prices[i]-min_so_far);
            }
        }
        return max_profit;

    }
};

// int main(){
//     vector<int> prices;
//     int x;
//     while(cin)
//     {
//         cin>>x;
//         prices.push_back(x);
//     }
//     Solution s;
//     cout<<s.maxProfit(prices)<<endl;
// }
