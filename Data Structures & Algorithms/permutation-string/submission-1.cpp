class Solution {
public:
    bool all0(int (&a)[26]) {
        for (auto x:a) {
            if (x!=0) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if (s1.length()>s2.length()) return false;
        int a[26]={0};
        for (auto x:s1) {
            a[x-'a']++;
        }
        for (int i=0;i<s1.length();i++) {
            a[s2[i]-'a']--;
        }
        if (all0(a)) return true;
        for (int i=s1.length();i<s2.length();i++) {
            a[s2[i]-'a']--;
            a[s2[i-s1.length()]-'a']++;
            if (all0(a)) return true;
        }
        return false;
    }
};
