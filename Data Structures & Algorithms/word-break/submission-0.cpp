class Solution {
public:

    bool helper(int i,string& s,unordered_set<string>& dict,vector<int>& dp) {
        if (i==s.size()) return true;
        if (dp[i]!=-1) return dp[i];
        bool ans=false;
        for (int k=s.size()-1;k>=i;k--) {
            if (dict.count(s.substr(i,k-i+1))) ans=ans|helper(k+1,s,dict,dp);
        }
        return dp[i]=ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (auto x:wordDict) {
            dict.insert(x);
        }
        vector<int> dp(s.size(),-1);
        return helper(0,s,dict,dp);
    }
};
