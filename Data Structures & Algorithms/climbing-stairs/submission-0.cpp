class Solution {
public:

    int helper(int i,int n,vector<int>& dp) {
        if (i>n) return 0;
        if (i==n) return 1;
        if (dp[i]!=-1) return dp[i];
        int l=helper(i+1,n,dp);
        int r=helper(i+2,n,dp);
        dp[i]=l+r;
        return dp[i];
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return helper(0,n,dp);
    }
};
