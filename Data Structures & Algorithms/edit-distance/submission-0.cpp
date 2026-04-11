// say Alhamdulillah

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string str1, string str2) {
    int s1=str1.size();
    int s2=str2.size();

    int dp[s1+1][s2+1];

    //base case
    for(int i = 0; i <=s1; i++) dp[i][0]=i;
    for(int i = 0; i <=s2; i++) dp[0][i]=i;

    for(int i = 1; i <=s1; i++)
    {
        for(int j = 1; j <=s2; j++)
        {
            int ins=dp[i][j-1]+1;      //cost of insert operation = 1
            int del=dp[i-1][j]+1;      //cost of delete operation = 1
            int subst=dp[i-1][j-1]+1;  //cost of replace operation = 1

            if(str1[i-1]==str2[j-1]) subst--;
            //(i th character of str1) = (j th character of str2)
            //So extra 1 replace operation is not nedded. So 1 is eliminated

            dp[i][j]=min(ins,min(del,subst));
        }
    }
    return dp[s1][s2];
    }
};
