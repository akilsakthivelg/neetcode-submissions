class TrieNode {
    public:
    unordered_map<char,TrieNode*> children;
    bool endOfWord;
};

class WordDictionary {
public:

    TrieNode* root;

    WordDictionary() {
        root= new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (auto &x:word) {
            if (cur->children.find(x)==cur->children.end()) {
                cur->children[x]=new TrieNode();
            }
            cur = cur->children[x];
        }
        cur->endOfWord=true;
    }
    
    bool dfs(int j,string word,TrieNode* cur) {
        for (int i=j;i<word.size();i++) {
            if (word[i]=='.') {
                for (auto x:cur->children) {
                    if (dfs(i+1,word,x.second)) return true;
                }
                return false;
            }
            if (cur->children.find(word[i])==cur->children.end()) return false;
            cur=cur->children[word[i]];
        }
        return cur->endOfWord;
    }

    bool search(string word) {
        return dfs(0,word,root);
    }
};
