/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        queue<TreeNode*> q;
        if (root) {
            ans+=to_string(root->val)+",";
            q.push(root);
        }
        else ans+="N,";
        while (!q.empty()) {
            auto t=q.front();
            q.pop();
            if (t->left) {
                ans+=to_string(t->left->val)+",";
                q.push(t->left);
            } else ans+="N,";
            if (t->right) {
                ans+=to_string(t->right->val)+",";
                q.push(t->right);
            } else ans+="N,";
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data=="N,") return NULL;
        queue<TreeNode*> q;
        string temp="";
        for (auto x:data) {
            if (x==',') {
                if (temp=="N") q.push(NULL);
                else q.push(new TreeNode(stoi(temp)));
                temp="";
            }
            else temp+=x;
        }
        queue<TreeNode*> q1;
        q1.push(q.front());
        auto root = q.front();
        q.pop();
        while (!q1.empty()) {
            auto t=q1.front();
            q1.pop();
            auto l=q.front();
            q.pop();
            auto r=q.front();
            q.pop();
            t->left=l;
            t->right=r;
            if (l) q1.push(l);
            if (r) q1.push(r);
        }
        return root;
    }
};
