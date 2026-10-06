class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int row=h.size(),col=h[0].size();
        vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
        vector<vector<int>> dist(row,vector<int>(col,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        dist[0][0]=0;
        pq.push({0,0,0});
        while (!pq.empty()) {
            int d=pq.top()[0];
            int r=pq.top()[1];
            int c=pq.top()[2];
            pq.pop();
            if (r==row-1 && c==col-1) return d;
            if (dist[r][c]<d) continue;
            for (auto x:dir) {
                int nr=r+x[0];
                int nc=c+x[1];
                if (nr<0 || nc<0 || nr>=row || nc>=col) continue;
                int nd=max(d,abs(h[r][c]-h[nr][nc]));
                if (nd<dist[nr][nc]) {
                    dist[nr][nc]=nd;
                    pq.push({nd,nr,nc});
                }
            }
        }
        return 0;
    }
};