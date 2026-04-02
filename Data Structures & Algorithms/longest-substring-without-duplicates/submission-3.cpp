class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int n=s.length();
        int i=0,j=0;
        int freq[256]={0};
        while (i<n && j<n) {
            freq[s[j]]++;
            while (freq[s[j]]>1) {
                freq[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
        
    }
};
