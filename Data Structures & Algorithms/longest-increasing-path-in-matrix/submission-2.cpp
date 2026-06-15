class Solution {
public:

    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

    int dfs(int i,int j,vector<vector<int>>&dp,int prev,vector<vector<int>>& arr) {
        if (i<0 || j<0 || i>=arr.size() || j>=arr[0].size() || prev>=arr[i][j]) return 0;
        int ans=0;
        if (dp[i][j]!=-1) return dp[i][j];
        for (auto x:dir) {
            ans=max(ans,1+dfs(i+x[0],j+x[1],dp,arr[i][j],arr));
        }
        return dp[i][j]=ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<vector<int>> dp(r+1,vector<int>(c+1,-1));
        int ans=1;
        for (int i=0;i<r;i++) {
            for (int j=0;j<c;j++) {
                if (dp[i][j]==-1) {
                    dp[i][j]=dfs(i,j,dp,INT_MIN,matrix);
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
