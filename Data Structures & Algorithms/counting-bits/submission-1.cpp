class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp;
        dp.push_back(0);
        int offset=1;
        int m=1;
        while (m<=n) {
            if (m==offset*2) offset*=2;
            int c=1+dp[m-offset];
            dp.push_back(c);
            m++;

        }
        return dp;
    }
};
