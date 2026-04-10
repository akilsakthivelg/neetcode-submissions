class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int ans=0;
        vector<vector<int>> adj(n);
        for (auto x:edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<bool> visited(n,false);
        queue<int> q;
        for (int i=0;i<n;i++) {
            if (visited[i]) continue;
            ans++;
            q.push(i);
            while (!q.empty()) {
                int e=q.front();
                q.pop();
                for (auto x:adj[e]) {
                    if (!visited[x]) {
                        visited[x]=true;
                        q.push(x);
                    }
                }
            }

        }
        return ans;
    }
};
