class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        double ans=x;
        for(int i=1;i<abs(n);i++)
        {
            ans*=x;
        }
        if(n<0) ans=1/ans;
        return ans;
    }
};
