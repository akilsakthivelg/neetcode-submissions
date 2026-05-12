class Solution {
public:

    bool isPal(string s) {
        if (s.length()==0) return false;
        for(int i=0;i<s.length()/2;i++) {
            if (s[i]!=s[s.length()-1-i]) return false;
        }
        return true;
    }

    void palindrome(string& s,int i,vector<string>& temp,vector<vector<string>>& ans) {
        if (i>=s.length())  {
            ans.push_back(temp);
            return;
        }
        string t;
        for (int j=i+1;j<=s.length();j++) {
            t=s.substr(i,j-i);
            cout << t << endl;
            if (isPal(t)) {
                temp.push_back(t);
                palindrome(s,j,temp,ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        palindrome(s,0,temp,ans);
        return ans;
    }
};
