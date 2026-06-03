class Solution {
public:

    int helper(int i,vector<int>& prices,bool sold,vector<vector<int>>& dp) {
        if (i>=prices.size()) return 0;
        if (dp[i][sold]!=-1) return dp[i][sold];
        if (sold)
            dp[i][sold]= helper(i+1,prices,false,dp)-prices[i];
        else
            dp[i][sold]=prices[i]+helper(i+2,prices,true,dp);
        dp[i][sold]=max(dp[i][sold],helper(i+1,prices,sold,dp));
        return dp[i][sold];

    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return helper(0,prices,true,dp);
    }
};
