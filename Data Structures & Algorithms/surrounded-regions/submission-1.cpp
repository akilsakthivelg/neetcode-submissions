class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> change(n,vector<bool>(m,true));
        queue<pair<int,int>> q;
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        
        for (int i=0;i<n;i++) {
            if (board[i][0]=='O') q.push({i,0});
            if (board[i][m-1]=='O') q.push({i,m-1});
        }
        for (int i=0;i<m;i++) {
            if (board[0][i]=='O') q.push({0,i});
            if (board[n-1][i]=='O') q.push({n-1,i});
        }

        while (!q.empty()) {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            change[i][j]=false;
            for (auto x:dir) {
                int a=i+x[0];
                int b=j+x[1];
                if (a<0 || b<0 || a>=n || b>=m || board[a][b]=='X' || change[a][b]==false) continue;
                q.push({a,b});
            }
        }
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (change[i][j]) board[i][j]='X';
            }
        }

    }
};
