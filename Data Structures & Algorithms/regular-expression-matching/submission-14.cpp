class Solution {
public:

    bool helper(int i,int j,string& s,string& p,vector<vector<int>>& dp) {
        if (dp[i][j]!=-1) return dp[i][j];
        if (j==p.size()) return dp[i][j]=(i==s.size());
        bool match = i<s.size() && (s[i]==p[j] || p[j]=='.');
        bool ans;
        if (j+1<p.size() && p[j+1]=='*') {
            ans=helper(i,j+2,s,p,dp);
            if (match) ans|=helper(i+1,j,s,p,dp);
        } else ans=match && helper(i+1,j+1,s,p,dp);
        return dp[i][j]=ans;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
        return helper(0,0,s,p,dp);
    }
};
