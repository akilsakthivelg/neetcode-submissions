class Solution {
public:

    vector<int> topoSort(int k,vector<vector<int>>& v) {
        vector<int> indeg(k+1);
        vector<vector<int>> adj(k+1);
        vector<int> order;
        for (auto &x:v) {
            adj[x[0]].push_back(x[1]);
            indeg[x[1]]++;
        }
        queue<int> q;
        for (int i=1;i<=k;i++) {
            if (indeg[i]==0) q.push(i);
        }
        while (!q.empty()) {
            int n=q.front();
            order.push_back(n);
            q.pop();
            for (auto &x:adj[n]) {
                indeg[x]--;
                if (indeg[x]==0) {
                    q.push(x);
                }
            }
        }
        if (order.size()==k) return order;
        return {};
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> row=topoSort(k,rowConditions);
        vector<int> col=topoSort(k,colConditions);
        if (row.size()==0 || col.size()==0) return {};
        vector<vector<int>> ans(k,vector<int>(k));
        unordered_map<int,pair<int,int>> m;
        for (int i=0;i<k;i++)
            m[row[i]]={i,0};
        for (int i=0;i<k;i++)
            m[col[i]].second=i;
        for (int i=1;i<=k;i++) ans[m[i].first][m[i].second]=i;
        return ans;
    }
};