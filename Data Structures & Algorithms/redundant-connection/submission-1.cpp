class Solution {
public:

    int find(int x,vector<int>& parent) {
        if (x==parent[x]) return x;
        return find(parent[x],parent);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> parent(n+1);
        for (int i=1;i<=n;i++) parent[i]=i;
        for (auto x:edges) {
            int u=find(x[0],parent);
            int v=find(x[1],parent);
            if (u==v) return x;
            parent[u]=v;
        }
        return {-1,-1};
    }
};
