class Node {
    public:
    unordered_map<char,Node*> children;
    bool isEnd;
};

class Solution {
public:
    Node* root = new Node();

    void insert(string s) {
        Node* curr = root;
        for (auto x:s) {
            if (curr->children.find(x)==curr->children.end())
                curr->children[x]=new Node();
            curr=curr->children[x];
        }
        curr->isEnd=true;
    }

    int minExtraChar(string s, vector<string>& dict) {
        for (auto x:dict) {
            insert(x);
        }
        int n=s.size();
        vector<int> dp(n+1);
        for (int i=n-1;i>=0;i--) {
            dp[i]=1+dp[i+1];
            Node* curr=root;
            for (int j=i;j<n;j++) {
                if (curr->children.find(s[j])==curr->children.end()) break;
                curr=curr->children[s[j]];
                if (curr->isEnd) dp[i]=min(dp[i],dp[j+1]);
            }
        }
        return dp[0];
    }
};