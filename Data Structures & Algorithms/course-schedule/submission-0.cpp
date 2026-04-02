class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        for (auto x:pre) {
            adj[x[0]].push_back(x[1]);
            indeg[x[1]]++;
        }
        queue<int> q;

        for (int i=0;i<n;i++) {
            if (indeg[i]==0) q.push(i);
        }
        int tot=0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            tot++;
            for (auto x:adj[node]) {
                indeg[x]--;
                if (indeg[x]==0) q.push(x);
            }
        }
        return tot==n;
    }
};
