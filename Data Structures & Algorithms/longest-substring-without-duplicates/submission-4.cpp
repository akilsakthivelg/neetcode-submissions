class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};
        int i=0,j=0;
        int n=s.size();
        int ans=0;
        while (i<n && j<n) {
            freq[s[j]]++;
            while (freq[s[j]]>1) {
                freq[s[i++]]--;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
