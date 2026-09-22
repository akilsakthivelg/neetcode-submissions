class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        int r=grid.size();
        int c=grid[0].size();
        for (int i=0;i<r;i++) {
            for (int j=0;j<c;j++) {
                if (grid[i][j]) {
                    ans+=4;
                    if (i && grid[i-1][j]) ans-=2;
                    if (j && grid[i][j-1]) ans-=2;
                }
            }
        }
        return ans;
    }
};