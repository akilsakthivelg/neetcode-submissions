/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        unordered_map<int,Node*> m;
        queue<Node*> q;
        q.push(node);
        Node* N = new Node(node->val);
        m[node->val]=N;
        while (!q.empty()) {
            auto t=q.front();
            q.pop();
            vector<Node*> temp;
            for (auto x:t->neighbors) {
                if (m.find(x->val)==m.end()) {
                    Node* N = new Node(x->val);
                    m[x->val]=N;
                    q.push(x);
                }
                temp.push_back(m[x->val]);
            }
            m[t->val]->neighbors=temp;
        }
        return N;
    }
};

