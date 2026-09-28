class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26);
        for (auto x:s) freq[x-'a']++;
        
        int mi=max_element(freq.begin(),freq.end()) - freq.begin();
        if (freq[mi]>(s.size()+1)/2) return "";

        string ans(s.size(),'a');

        int i=0;
        while (freq[mi]) {
            ans[i]+=mi;
            i+=2;
            freq[mi]--;
        }
        
        for (int j=0;j<26;j++) {
            while (freq[j]--) {
                if (i>=s.size()) i=1;
                ans[i]+=j;
                i+=2;
            }
        }
        return ans;
    }
};