class Solution {
public:

    int ans=0;

    bool isSafe(int i,int j,vector<vector<bool>>& visited) {
        int n=visited.size();
        int a=i,b=j;
        while (a>=0 && b>=0) if (visited[a--][b--]) return false;
        a=i,b=j;
        while (a<n && b<n) if (visited[a++][b++]) return false;
        a=i,b=j;
        while (a>=0 && b<n) if (visited[a--][b++]) return false;
        a=i,b=j;
        while (a<n && b>=0) if (visited[a++][b--]) return false;
        for (int k=0;k<n;k++) if (visited[i][k] || visited[k][j]) return false;
        return true;
    }

    void helper(int k,int n,int q,vector<vector<bool>>& visited) {
        int i=k/n;
        int j=k%n;
        if (k==n*n) {
            if (q==0) ans++;
            return;
        }
        if (isSafe(i,j,visited) && q) {
            visited[i][j]=true;
            helper(k+1,n,q-1,visited);
            visited[i][j]=false;
        }
        helper(k+1,n,q,visited);
    }

    int totalNQueens(int n) {
        ans=0;
        vector<vector<bool>> visited(n,vector<bool>(n));
        helper(0,n,n,visited);
        return ans;
    }
};