class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto x:flights) {
            adj[x[0]].push_back({x[1],x[2]});
        }
        vector<int> sd(n,INT_MAX);
        queue<pair<int,int>> q;
        q.push({src,0});
        sd[src]=0;
        for (int i=0;i<=k;i++) {
            vector<int> temp=sd;
            int s=q.size();
            while (s--) {
                int n=q.front().first;
                int c=q.front().second;
                q.pop();
                for (auto x:adj[n]) {
                    if (sd[x.first]==INT_MAX || sd[n]+x.second<temp[x.first] ) {
                        temp[x.first]=c+x.second;
                    }
                    q.push({x.first,x.second+sd[n]});
                }
            }
            sd=temp;
        }
        return sd[dst]==INT_MAX?-1:sd[dst];
    }
};
