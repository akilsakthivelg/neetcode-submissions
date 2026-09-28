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

    pair<int,int> helper(TreeNode* root) {
        if (!root) return {0,0};
        pair<int,int> l = helper(root->left);
        pair<int,int> r = helper(root->right);
        return {root->val+l.second+r.second,max({l.first+r.first,l.second+r.second,l.first+r.second,l.second+r.first})};
    }

    int rob(TreeNode* root) {
        pair<int,int> ans = helper(root);
        return max(ans.first,ans.second);
    }
};