class Solution {
public:
    int characterReplacement(string s, int k) {
        int max_len=0;
        int freq[26]={0};
        int i=0,j=0;
        int n=s.length();
        int max_freq=0;
        while (i<n && j<n) {
            freq[s[j]-'A']++;
            max_freq=max(max_freq,freq[s[j]-'A']);
            while ( (j-i+1) - max_freq  >  k ) {
                freq[s[i]-'A']--;
                i++;
            }
            max_len=max(max_len,j-i+1);
            j++;
        }
        return max_len;
    }
};
