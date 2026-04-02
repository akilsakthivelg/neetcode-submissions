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

class Solution {
public:

    bool makeV(TreeNode* root,vector<TreeNode*>& a,TreeNode* p) {
        if (!root) return false;
        a.push_back(root);
        if (root==p) {
            return true;
        }
        if (makeV(root->left,a,p)) return true;
        if (makeV(root->right,a,p)) return true;
        a.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> a,b;
        makeV(root,a,p);
        makeV(root,b,q);
        int i=0;
        while (i<a.size() && i<b.size() && a[i]==b[i]) i++;
        return a[i-1];
        
    }
};
