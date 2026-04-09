class Solution {
public:

    vector<vector<int>> dir = {{0,-1},{0,1},{1,0},{-1,0}};

    bool helper(int i,int j,int k,vector<vector<char>>& board,string& word,vector<vector<bool>>& visited) {
        if (k==word.size()) return true;
        if (i<0 || j<0 || i==board.size() || j==board[0].size() || visited[i][j]) return false;
        if (board[i][j]!=word[k]) return false;
        visited[i][j]=true;
        for (auto x:dir) {
            if (helper(i+x[0],j+x[1],k+1,board,word,visited)) return true;
        }
        visited[i][j]=false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (helper(i,j,0,board,word,visited)) return true;
            }
        }
        return false;
    }
};
