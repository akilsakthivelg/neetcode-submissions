class Solution {
public:

    bool allPresent(int freq[]) {
        for (int i=0;i<128;i++) {
            if (freq[i]>0) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";
        string ans="";
        int freq[128]={0};
        for (auto c:t) freq[c]++;
        int i=0;
        int j=0;
        int n=s.length();
        while (i<n && j<n) {
            freq[s[j]]--;
            while (allPresent(freq)) {
                if (ans=="" || ans.length() > j-i+1) {
                    ans=s.substr(i,j-i+1);
                }
                freq[s[i]]++;
                i++;
            }
            j++;
        }
        return ans;
    }
};
