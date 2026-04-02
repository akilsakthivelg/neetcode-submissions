class Solution {
public:

    void dfs(int i,int j,int parent,vector<vector<int>>& heights,vector<vector<bool>>& ocean) {
        if (i<0 || i>=heights.size() || j<0 || j>=heights[0].size() || ocean[i][j] || heights[i][j]<parent) return;
        ocean[i][j]=true;
        dfs(i,j-1,heights[i][j],heights,ocean);
        dfs(i,j+1,heights[i][j],heights,ocean);
        dfs(i+1,j,heights[i][j],heights,ocean);
        dfs(i-1,j,heights[i][j],heights,ocean);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<bool>> pacific(n,vector<bool>(m,false));
        vector<vector<bool>> atlantic(n,vector<bool>(m,false));
        for (int i=0;i<n;i++) {
            dfs(i,0,INT_MIN,heights,pacific);
            dfs(i,m-1,INT_MIN,heights,atlantic);
        }

        for (int i=0;i<m;i++) {
            dfs(0,i,INT_MIN,heights,pacific);
            dfs(n-1,i,INT_MIN,heights,atlantic);
        }

        vector<vector<int>> ans;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (pacific[i][j] && atlantic[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
