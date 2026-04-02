class Solution {
public:


    int ans=0;
    void helper(int i,int target,vector<int>& nums) {
        if (i==nums.size()) {
            if (target==0) ans++;
            return;
        }
        helper(i+1,target-nums[i],nums);
        helper(i+1,target+nums[i],nums);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // vector<vector<int>> dp(nums.size(),vector<int>(4000,-1));
        helper(0,target,nums);
        return ans;
    }
};
