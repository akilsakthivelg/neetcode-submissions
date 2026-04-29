class Solution {
public:

    vector<vector<int>> dir = {{0,-1},{0,1},{-1,0},{1,0}};

    void dfs(int i,int j,vector<vector<char>>& grid) {
        if (i>=grid.size() || i<0 || j>=grid[0].size() || j<0 || grid[i][j]=='0') return;
        grid[i][j]='0';
        for (auto x:dir) {
            dfs(i+x[0],j+x[1],grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for (int i=0;i<grid.size();i++) {
            for (int j=0;j<grid[0].size();j++) {
                if (grid[i][j]=='1') {
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};
