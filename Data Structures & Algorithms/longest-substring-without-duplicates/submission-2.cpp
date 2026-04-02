class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length()<1) return 0;
        int i=0,j=1;
        unordered_map<char,int> map;
        int max=1,c=1;
        map[s[0]]++;
        while(j<s.length()) {
            if (map[s[j]]>0) {
                map[s[i]]--;
                i++;
                c--;
            } else {
                c++;
                map[s[j]]++;
                j++;
            }
            if (max<c) max=c;
        }
        return max;
    }
};
