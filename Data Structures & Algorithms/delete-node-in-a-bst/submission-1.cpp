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

    TreeNode* getSuccessor(TreeNode* root) {
        root=root->left;
        while (root->right) root=root->right;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val>key) {
            root->left=deleteNode(root->left,key);
        } else if (root->val<key) {
            root->right=deleteNode(root->right,key);
        } else {
            if (root->left==nullptr) {
                TreeNode* t = root->right;
                delete root;
                return t;
            } else if (root->right==nullptr) {
                TreeNode* t = root->left;
                delete root;
                return t;
            } else {
                TreeNode* s = getSuccessor(root);
                swap(root->val,s->val);
                root->left = deleteNode(root->left,key);
                return root;
            }
        }
        return root;
    }
};