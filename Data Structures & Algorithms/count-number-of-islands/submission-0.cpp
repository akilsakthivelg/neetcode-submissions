class Solution {
public:

    vector<vector<int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};

    void dfs(int i,int j,vector<vector<char>> &grid,vector<vector<bool>>& visited) {
        int r=grid.size();
        int c=grid[0].size();
        visited[i][j]=true;
        for (auto x:dir) {
            int ni=i+x[0];
            int nj=j+x[1];
            if (ni<0 || nj<0 || ni>=r || nj>=c || visited[ni][nj] || grid[ni][nj]=='0') continue;
            dfs(ni,nj,grid,visited);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int ans=0;
        vector<vector<bool>> visited(r,vector<bool>(c));
        for (int i=0;i<r;i++) {
            for (int j=0;j<c;j++) {
                if (grid[i][j]=='0' || visited[i][j]) continue;
                dfs(i,j,grid,visited);
                ans++;
            }
        }
        return ans;
    }
};
