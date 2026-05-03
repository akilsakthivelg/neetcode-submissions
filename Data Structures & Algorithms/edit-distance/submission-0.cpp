class Solution {
public:

    int helper(int i,int j,string& s1,string& s2,vector<vector<int>>& dp) {
        if (i==s1.size()) {
            return s2.size()-j;
        }
        if (j==s2.size()) {
            return s1.size()-i;
        }
        if (dp[i][j]!=-1) return dp[i][j];
        int a=INT_MAX,b=INT_MAX,c,d;
        if (s1[i]==s2[j]) a=helper(i+1,j+1,s1,s2,dp);
        else b=1+helper(i+1,j+1,s1,s2,dp);
        c=1+helper(i,j+1,s1,s2,dp);
        d=1+helper(i+1,j,s1,s2,dp);
        return dp[i][j]=min({a,b,c,d});
    }

    int minDistance(string s1, string s2) {
        vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),-1));
        return helper(0,0,s1,s2,dp);
    }
};
