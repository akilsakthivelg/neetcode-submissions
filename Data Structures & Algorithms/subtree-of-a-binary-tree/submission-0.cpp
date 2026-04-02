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

    bool isSame(TreeNode* a,TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;
        if (a->val!=b->val) return false;
        if (!isSame(a->left,b->left)) return false;
        if (!isSame(a->right,b->right)) return false;
        return true;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root==NULL) return false;
        if (isSame(root,subRoot)) return true;
        if (isSubtree(root->left,subRoot)) return true;
        if (isSubtree(root->right,subRoot)) return true;
        return false;
    }
};
