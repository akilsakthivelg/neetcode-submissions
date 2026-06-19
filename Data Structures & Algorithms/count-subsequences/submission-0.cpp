class Solution {
public:

    int helper(int i,int j,string &s,string &t,vector<vector<int>>& dp) {
        if (j==t.size()) return 1;
        if (i==s.size()) return 0;
        if (dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if (s[i]==t[j]) ans=helper(i+1,j+1,s,t,dp);
        ans+=helper(i+1,j,s,t,dp);
        return dp[i][j]=ans;
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
        return helper(0,0,s,t,dp);
    }
};
