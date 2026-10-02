class Solution {
public:
    void helper(int i,string& s,vector<string>& temp,unordered_set<string>& words,vector<vector<string>>& ans) {
        int n=s.size();
        if (i==n) {
            ans.push_back(temp);
            return;
        }
        for (int j=i;j<n;j++) {
            string sub = s.substr(i,j-i+1);
            if (words.count(sub)) {
                temp.push_back(sub);
                helper(j+1,s,temp,words,ans);
                temp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for (auto x:wordDict) words.insert(x);
        vector<vector<string>> ans;
        vector<string> t;
        helper(0,s,t,words,ans);
        vector<string> res;
        for (auto x:ans) {
            string e=x[0];
            for (int i=1;i<x.size();i++) e+=(" "+x[i]);
            res.push_back(e);
        }
        return res;
    }
};