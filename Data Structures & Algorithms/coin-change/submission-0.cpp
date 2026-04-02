class Solution {
public:

    int ans=INT_MAX;

    int helper(int i,vector<int>& coins,int target,vector<vector<int>> &dp) {
        if (target==0) {
            return 0;
        }
        if (i==coins.size()) return 1e9;
        if (target<0) return 1e9;
        if (dp[i][target]!=-1) return dp[i][target];
        int take = 1+helper(i,coins,target-coins[i],dp);
        int ntake = helper(i+1,coins,target,dp);
        dp[i][target]=min(take,ntake);
        return dp[i][target];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans = helper(0,coins,amount,dp);
        if (ans>=1e9) return -1;
        return ans;
    }
};
