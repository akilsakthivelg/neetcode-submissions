class Solution {
public:
vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<tuple<int,int,int>> q;
        int count=0;
        for (int i=0;i<grid.size();i++) {
            for (int j=0;j<grid[0].size();j++) {
                if (grid[i][j]==2) q.push({i,j,0});
                if (grid[i][j]==1) count++;
            }
        }
        int maxt=0;
        while (!q.empty()) {
            auto [i,j,t]=q.front();
            q.pop();
            for (auto x:dir) {
                int n=i+x[0];
                int m=j+x[1];
                if (n>=0 && n<grid.size() && m>=0 && m<grid[0].size() && grid[n][m]==1) {
                    grid[n][m]=2;
                    q.push({n,m,t+1});
                    maxt=t+1;
                    count--;
                }
            }
        }
        if (count!=0) return -1;
        return maxt;
    }
};
