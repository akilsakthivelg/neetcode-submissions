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
        q.push(root);
        while (!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if (t) ans+=to_string(t->val);
            else ans+="N";
            ans+=",";
            if (t) q.push(t->left);
            if (t) q.push(t->right);
        }
        return ans;
    }

    TreeNode* getNode(string s,int& j) {
        string data="";
        if (s[j]=='N') {
            j++;
            j++;
            return NULL;
        }
        while (j<s.length() && s[j]!=',') {
            data+=s[j];
            j++;
        }
        j++;
        return new TreeNode(stoi(data));
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0;
        TreeNode* root = getNode(data,i);
        queue<TreeNode*> q;
        q.push(root);
        int n=data.length();
        while (i<n) {
            TreeNode* t=getNode(data,i);
            TreeNode* node=q.front();
            q.pop();
            node->left=t;
            if (t) q.push(t);
            if (i>=n) break;
            t=getNode(data,i);
            node->right=t;
            if (t) q.push(t);
        }
        return root;
    }
};
