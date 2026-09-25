class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        int g = gcd(s1.size(),s2.size());
        for (int i=0;i<s1.size();i++)
            if (s1[i]!=s1[i%g]) return "";
        for (int i=0;i<s2.size();i++)
            if (s2[i]!=s1[i%g]) return "";
        return s1.substr(0,g);
    }
};