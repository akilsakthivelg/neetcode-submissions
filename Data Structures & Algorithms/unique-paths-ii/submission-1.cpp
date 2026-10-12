class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        if (grid[0][0] || grid[r-1][c-1]) return 0;
        vector<vector<int>> dp(r+1,vector<int>(c+1));
        for (int i=r-1;i>=0;i--) {
            for (int j=c-1;j>=0;j--) {
                if (grid[i][j]) continue;
                if (i==r-1 && j==c-1) {
                    dp[i][j]=1;
                    continue;
                }
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};