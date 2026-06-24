class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> mx(n,vector<int>(m,1e9));
        pq.push({grid[0][0],{0,0}});
        mx[0][0]=grid[0][0];
        while (!pq.empty()) {
            int t=pq.top().first;
            int i=pq.top().second.first,j=pq.top().second.second;
            pq.pop();
            for (auto x:dir) {
                int ni=i+x[0];
                int nj=j+x[1];
                if (ni>=0 && nj>=0 && ni<n && nj<m && mx[ni][nj]>t) {
                    pq.push({max(t,grid[ni][nj]),{ni,nj}});
                    mx[ni][nj]=max(t,grid[ni][nj]);
                }
            }
        }
        return mx[n-1][m-1];

    }
};
