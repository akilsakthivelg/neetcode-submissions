class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int max_time=0;
        int fresh_count=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<tuple<int,int,int>> q;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (grid[i][j]==2) {
                    q.push({i,j,0});
                } else if (grid[i][j]==1) {
                    fresh_count++;
                }
            }
        }
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

        while (!q.empty()) {
            auto [i,j,t] = q.front();
            q.pop();
            for (auto x:dir) {
                int ni=i+x[0];
                int nj=j+x[1];
                if (ni<0 || nj<0 || ni>=n || nj>=m || grid[ni][nj]!=1) continue;
                q.push({ni,nj,t+1});
                grid[ni][nj]=2;
                max_time=t+1;
                fresh_count--;
            }
        }
        if (fresh_count) return -1;
        return max_time;
    }
};
