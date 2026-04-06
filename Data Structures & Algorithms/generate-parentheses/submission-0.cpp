class Solution {
public:

    void helper(int n,string& t,int d,vector<string>& ans) {
        if (n==0) {
            if (d==0) ans.push_back(t);
            return;
        }
        if (d>0) {
            t+=')';
            helper(n-1,t,d-1,ans);
            t.pop_back();
        }
        t+='(';
        helper(n-1,t,d+1,ans);
        t.pop_back();

    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string t="";
        helper(n*2,t,0,ans);
        return ans;
    }
};
