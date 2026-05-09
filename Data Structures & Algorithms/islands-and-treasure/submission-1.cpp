class Solution {
public:

vector<vector<int>> dir={{0,-1},{0,1},{1,0},{-1,0}};

    void dfs(int i,int j,vector<vector<int>>& grid,int d) {
        if (i<0 || j<0 || j>=grid[0].size() || i>=grid.size() ||grid[i][j]<d) return;
        grid[i][j]=d;
        for (auto x:dir) {
            dfs(i+x[0],j+x[1],grid,d+1);
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for (int i=0;i<grid.size();i++) {
            for (int j=0;j<grid[0].size();j++) {
                if (grid[i][j]==0) dfs(i,j,grid,0);
            }
        }
    }
};
