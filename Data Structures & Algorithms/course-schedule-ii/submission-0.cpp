class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> ans;
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        for (auto x:pre) {
            adj[x[1]].push_back(x[0]);
            indeg[x[0]]++;
        }
        queue<int> q;
        for (int i=0;i<n;i++) {
            if (indeg[i]==0) q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto x:adj[node]) {
                indeg[x]--;
                if (indeg[x]==0) q.push(x);
            }
        }
        if (ans.size()==n) return ans;
        return {};
    }
};
