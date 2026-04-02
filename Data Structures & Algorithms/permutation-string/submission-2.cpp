class Solution {
public:

    bool all0(int a[]) {
        for (int i=0;i<26;i++) if (a[i]) return false;
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int a[26]= {0};
        int i=0;
        for (i=0;i<s1.size();i++) {
            a[s1[i]-'a']--;
            a[s2[i]-'a']++;
        }
        if (all0(a)) return true;
        
        while (i<s2.length()) {
            a[s2[i]-'a']++;
            a[s2[i-s1.size()]-'a']--;
            if (all0(a)) return true;
            i++;
        }
        return false;

    }
};
