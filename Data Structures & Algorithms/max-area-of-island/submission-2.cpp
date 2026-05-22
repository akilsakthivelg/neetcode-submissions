class Solution {
public:

    vector<vector<int>> dir = {{0,-1},{0,1},{1,0},{-1,0}};

    int dfs(int i,int j,vector<vector<int>>& grid) {
        if (i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0) {
            return 0;
        }
        int ans=1;
        grid[i][j]=0;
        for (auto x:dir) {
            ans+=dfs(i+x[0],j+x[1],grid);
        }
        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for (int i=0;i<grid.size();i++) {
            for (int j=0;j<grid[0].size();j++) {
                ans=max(ans,dfs(i,j,grid));
            }
        }
        return ans;
    }
};
