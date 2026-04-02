class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length()!=t.length()) return false;
        vector<int> a(26,0);
        for (auto x:s) a[x-97]++;
        for (auto x:t) a[x-97]--;
        for (int i=0;i<26;i++) {
            if (a[i]!=0) return false;
        }
        return true;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
};
