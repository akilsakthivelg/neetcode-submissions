class Solution {
public:

    int helper(int i,vector<int>& prices, bool having, vector<vector<int>>& dp) {
        if (i>=prices.size()) return 0;
        if (dp[i][having]!=-1) return dp[i][having];
        if (having) dp[i][having] = prices[i] + helper(i+2,prices,false,dp);
        else dp[i][having] = helper(i+1,prices,true,dp) - prices[i];
        dp[i][having] = max(dp[i][having],helper(i+1,prices,having,dp));
        return dp[i][having];
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return helper(0,prices,false,dp);
    }
};
