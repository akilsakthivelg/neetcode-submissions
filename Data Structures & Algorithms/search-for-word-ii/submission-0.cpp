class TrieNode {
    public:
    bool isWordEnd;
    unordered_map<char,TrieNode*> children;
};

class Solution {
    public:

    TrieNode* head=new TrieNode();

    void addNode(string& word) {
        TrieNode* t = head;
        for (auto x:word) {
            if (t->children.find(x)==t->children.end()) {
                t->children[x]= new TrieNode();
            }
            t=t->children[x];
        }
        t->isWordEnd=true;
    }

    set<string> ans;
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

    void dfs(int i,int j,vector<vector<char>>& board,TrieNode* t,vector<vector<bool>>& visited,string temp) {
        if (i>=board.size() || j>=board[0].size() || i<0 || j<0 || visited[i][j] || t->children.find(board[i][j])==t->children.end()) return;
        visited[i][j]=true;
        temp.push_back(board[i][j]);
        if (t->children[board[i][j]]->isWordEnd) {
            ans.insert(temp);
        }
        for (auto x:dir) {
            dfs(i+x[0],j+x[1],board,t->children[board[i][j]],visited,temp);
        }
        visited[i][j]=false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (auto x:words) {
            addNode(x);
        }
        int r=board.size();
        int c=board[0].size();
        for (int i=0;i<r;i++) {
            for (int j=0;j<c;j++) {
                vector<vector<bool>> visited(r,vector<bool>(c));
                dfs(i,j,board,head,visited,"");
            }
        }
        vector<string> arr;
        for (auto x:ans) arr.push_back(x);
        return arr;
    }
};
