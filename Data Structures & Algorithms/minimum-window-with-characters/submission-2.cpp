class Solution {
public:

    bool allpos(int freq[]) {
        for (int i=0;i<256;i++) {
            if (freq[i]<0) return false;
        }
        return true;
    }  

    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        int freq[256] = {0};
        for (auto x:t) freq[x]--;
        int i=0;
        string ans=s;
        bool flag=false;
        for (int j=0;j<s.size();j++) {
            freq[s[j]]++;
            while (allpos(freq)) {
                string sub = s.substr(i,j-i+1);
                if (sub.size() < ans.size()) ans=sub;
                freq[s[i]]--;
                i++;
                flag=true;
            }
        }
        if (!flag) return "";
        return ans;
    }
};
