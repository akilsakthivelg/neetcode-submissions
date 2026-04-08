class Solution {
public:

    int pals(int i,int j,string& s) {
        if (i<0 || j>=s.size() || s[i]!=s[j]) return 0;
        return 1+pals(i-1,j+1,s);
    }

    int countSubstrings(string s) {
        int ans=0;
        for (int i=0;i<s.size();i++) {
            ans+=pals(i,i,s);
            ans+=pals(i,i+1,s);
        }
        return ans;
    }
};
