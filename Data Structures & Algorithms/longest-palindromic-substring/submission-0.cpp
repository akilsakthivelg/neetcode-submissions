class Solution {
public:

    bool ispal(string& s) {
        int i=0;
        int j=s.size()-1;
        while (i<j) {
            if (s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        string ans="";
        for (int i=0;i<s.size();i++) {
            for (int j=i;j<s.size();j++) {
                string temp=s.substr(i,j-i+1);
                if (ispal(temp)) {
                    if (ans.size()<temp.size()) ans=temp;
                }
            }
        }
        return ans;
    }
};
