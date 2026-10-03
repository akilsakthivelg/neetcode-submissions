class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
        vector<vector<bool>> adj(n,vector<bool>(n));
        vector<bool> ans;
        for (auto &x:pre) adj[x[0]][x[1]]=true;
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                for (int k=0;k<n;k++) {
                    adj[i][j]=adj[i][j] || (adj[i][k]&&adj[k][j]);
                }
            }
        }
        for (auto &x:q) {
            ans.push_back(adj[x[0]][x[1]]);
        }
        return ans;
    }
};