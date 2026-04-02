class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> dp(n);
        dp[0]={nums[0],0};
        dp[1]={nums[1],nums[0]};
        for (int i=2;i<n;i++) {
            dp[i]={max({dp[i-1].first,nums[i]+dp[i-1].second}),max({dp[i-1].first,dp[i-1].second})};
        }
        return max(dp[n-1].first,dp[n-1].second);
    }
};