class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.length()-1;
        while (i<j) {
            if (!((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122) || (s[i]>='0' && s[i]<='9'))) i++;
            else if (!((s[j]>=65 && s[j]<=90) || (s[j]>=97 && s[j]<=122) || (s[j]>='0' && s[j]<='9'))) j--;
            else if (tolower(s[i])!=tolower(s[j])) return false;
            else {i++;j--;}
        }
        return true;
    }
};
