class Solution {
public:

    vector<string> l = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    void helper(int i,string &s,string temp,vector<string>& ans) {
        if (i==s.size()) {
            ans.push_back(temp);
            return;
        }
        for (auto x:l[s[i]-'0']) {
            helper(i+1,s,temp+x,ans);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size()==0) return {};
        vector<string> ans;
        helper(0,digits,"",ans);
        return ans;
    }
};
