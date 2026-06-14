class TrieNode {
    public:
    unordered_map<char,TrieNode*> children;
    bool endOfWord;
};

class PrefixTree {
public:

    TrieNode* root;

    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur=root;
        for (auto x:word) {
            if (cur->children.find(x)==cur->children.end()) {
                cur->children[x]=new TrieNode();
            }
            cur = cur->children[x];
        }
        cur->endOfWord=true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (auto x:word) {
            if (cur->children.find(x)==cur->children.end()) {
                return false;
            }
            cur = cur->children[x];
        }
        return cur->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (auto x:prefix) {
            if (cur->children.find(x)==cur->children.end()) {
                return false;
            }
            cur = cur->children[x];
        }
        return true;
    }
};
