class Solution {
public:

    int ans=0;
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

    void bfs(vector<vector<int>>& grid,int r,int c,vector<vector<bool>> &visited) {
        int cnt=0;
        queue<pair<int,int>> q;
        visited[r][c]=true;
        q.push({r,c});
        while (!q.empty()) {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            cnt++;
            for (auto x:dir) {
                int ni=i+x[0];
                int nj=j+x[1];
                if (ni<0 || nj<0 || ni>=grid.size() || nj>=grid[0].size() || visited[ni][nj] || grid[ni][nj]==0) continue;
                q.push({ni,nj});
                visited[ni][nj]=true;
            }
        }
        ans=max(ans,cnt);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        ans=0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (grid[i][j] && !visited[i][j]) {
                    bfs(grid,i,j,visited);
                }
            }
        }
        return ans;
    }
};
