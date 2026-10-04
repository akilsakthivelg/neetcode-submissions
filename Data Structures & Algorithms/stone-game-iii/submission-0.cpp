class Solution {
public:
    string stoneGameIII(vector<int>& stone) {
        int n=stone.size();
        vector<int>dp(n+1,INT_MIN);
        dp[n]=0;
        for (int i=n-1;i>=0;i--) {
            int tot = 0;
            for (int j=i;j<min(i+3,n);j++) {
                tot+=stone[j];
                dp[i]=max(dp[i],tot-dp[j+1]);
            }
        }
        if (dp[0]==0) return "Tie";
        return dp[0]>0?"Alice":"Bob";
    }
};