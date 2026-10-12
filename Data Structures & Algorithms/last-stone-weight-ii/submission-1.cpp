class Solution {
public:

    int helper(int i,int target,int tot,int sum,vector<int>& stones,vector<vector<int>>& dp) {
        if (i>=stones.size() || tot>=target) {
            return abs(tot-(sum-tot));
        }
        if (dp[i][tot]!=-1) return dp[i][tot];
        return dp[i][tot]=min(
            helper(i+1,target,tot+stones[i],sum,stones,dp),
            helper(i+1,target,tot,sum,stones,dp)
        );
    }

    int lastStoneWeightII(vector<int>& stones) {
        int sum=accumulate(stones.begin(),stones.end(),0);
        int target=sum/2;
        int n=stones.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return helper(0,target,0,sum,stones,dp);
    }
};