class Solution {
public:
    bool validPalindrome(string s) {
        bool used = false;
        int i=0,j=s.size()-1;
        while (i<j) {
            if (s[i]==s[j]) i++,j--;
            else break;
        }
        int a=i+1,b=j;
        int ans1=true;
        while (a<b && ans1) {
            if (s[a]!=s[b]) ans1=false;
            a++,b--;
        }
        a=i,b=j-1;
        bool ans2=true;
        while (a<b && ans2) {
            if (s[a]!=s[b]) ans2=false;
            a++,b--;
        }
        return ans1||ans2;
    }
};