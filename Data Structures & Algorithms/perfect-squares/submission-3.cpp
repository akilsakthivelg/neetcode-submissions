class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for (int t=1;t<=n;t++) {
            for (int s=1;s*s<=t;s++) {
                dp[t]=min(dp[t],1+dp[t-s*s]);
            }
        }
        return dp[n];
    }
};