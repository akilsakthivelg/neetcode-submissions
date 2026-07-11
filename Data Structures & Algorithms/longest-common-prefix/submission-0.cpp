class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int l=strs[0].size();
        for (int i=1;i<strs.size();i++) {
            int s=0;
            for (int j=0;j<l && j<strs[i].size();j++) {
                if (strs[i-1][j]!=strs[i][j]) break;
                s++;
            }
            l=s;
        }
        return strs[0].substr(0,l);
    }
};