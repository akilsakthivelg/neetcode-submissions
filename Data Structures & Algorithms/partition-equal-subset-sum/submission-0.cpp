class Solution {
public:

    bool helper(int i,int target,vector<int>& nums, vector<vector<int>>& dp) {
        if (target==0) return true;
        if (i==nums.size()) return false;
        if (dp[i][target]!=-1) return dp[i][target];
        bool tk = false;
        if (target-nums[i]>=0) tk=helper(i+1,target-nums[i],nums,dp);
        bool ntk=helper(i+1,target,nums,dp);
        return dp[i][target]=tk||ntk;
    }

    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if (sum%2) return false;
        vector<vector<int>> dp(nums.size(),vector<int>(sum/2+1,-1));
        return helper(0,sum/2,nums,dp);
    }
};
