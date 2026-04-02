class Solution {
public:
    
    int helper(int i,int target,vector<int> &coins,vector<vector<int>>& dp) {
        if (target==0) return 1;
        if (i==coins.size()) return 0;
        if (target < 0) return 0;
        if (target > 5000) return 0;
        if (dp[i][target]!=-1) return dp[i][target];
        int take = helper(i,target-coins[i],coins,dp);
        int ntake = helper(i+1,target,coins,dp);
        dp[i][target]= take + ntake;
        return dp[i][target];
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(5001,-1));
        return helper(0,amount,coins,dp);
    }
};
