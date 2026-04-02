class Solution {
public:
int t=0;
    int helper(int i,int target,vector<int>& nums,vector<vector<int>>& dp) {
        if (i==nums.size()) {
            if (target==0) return 1;
            return 0;
        }
        if (dp[i][target]!=-1) return dp[i][target];
        int take=0;
        if (target-nums[i] >= 0) take=helper(i+1,target-nums[i],nums,dp);
        int ntake = helper(i+1,target,nums,dp);
        dp[i][target]=take+ntake;
        return dp[i][target];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if (sum-target<0 || (sum-target)%2!=0) return 0;
        int k=(sum-target)/2;
        vector<vector<int>> dp(nums.size(),vector<int>(k+1,-1));
        return helper(0,k,nums,dp);
    }
};



// BRUTE FORCE IN RECURSION BACKTRACKING

// class Solution {
// public:


//     int ans=0;
//     void helper(int i,int target,vector<int>& nums) {
//         if (i==nums.size()) {
//             if (target==0) ans++;
//             return;
//         }
//         helper(i+1,target-nums[i],nums);
//         helper(i+1,target+nums[i],nums);
//     }

//     int findTargetSumWays(vector<int>& nums, int target) {
//         // vector<vector<int>> dp(nums.size(),vector<int>(4000,-1));
//         helper(0,target,nums);
//         return ans;
//     }
// };
