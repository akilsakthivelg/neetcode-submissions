class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n==1) return {0};
        vector<vector<int>> adj(n);
        for (auto x:edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int> edge_count(n);
        queue<int> leaves;
        for (int i=0;i<n;i++) {
            edge_count[i]=adj[i].size();
            if (adj[i].size()==1) {
                leaves.push(i);
            }
        }
        while (!leaves.empty()) {
            if (n<=2) {
                vector<int> ans;
                while (!leaves.empty()) {
                    ans.push_back(leaves.front());
                    leaves.pop();
                }
                return ans;
            }
            int s=leaves.size();
            for (int i=0;i<s;i++) {
                int node = leaves.front();
                leaves.pop();
                n--;
                for (auto &x:adj[node]) {
                    edge_count[x]--;
                    if (edge_count[x]==1) leaves.push(x);
                }
            }
        }
        return {};
    }
};