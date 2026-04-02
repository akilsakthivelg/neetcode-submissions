class Solution {
public:

    bool dfs(int n,int p,vector<vector<int>>& adjL,vector<bool>& visited) {
        visited[n]=true;
        for (auto x:adjL[n]) {
            if (!visited[x]) dfs(x,n,adjL,visited);
            else if (x!=p) return true;
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        
        vector<bool> visited(n,false);
        vector<vector<int>> adjL(n);
        for (auto x:edges) {
            adjL[x[0]].push_back(x[1]);
            adjL[x[1]].push_back(x[0]);
        }
        if (dfs(0,-1,adjL,visited)) return false;
        for (auto x:visited) if (!x) return false;
        return true;
    }
};
