class Solution {
public:
    int characterReplacement(string s, int k) {
        int t = 0;
        int i=0,j=0;
        int n=s.size();
        int freq[26] = {0};
        int maxF = 0;
        int ans=0;
        while (i<n && j<n) {
            freq[s[j]-'A']++;
            maxF = max(maxF,freq[s[j]-'A']);
            t++;
            while (t-maxF > k) {
                freq[s[i]-'A']--;
                t--;
                i++;
            }
            ans=max(t,ans);
            j++;
        }
        return ans;
    }
};
