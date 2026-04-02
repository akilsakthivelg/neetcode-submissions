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

    int ind=0;

    TreeNode* helper(vector<int>& pre,vector<int>& inorder,int s,int e) {
        if (ind>=pre.size() || s>e || s<0 || s>=pre.size() || e<0 || e>=pre.size()) return NULL;
        TreeNode* root = new TreeNode(pre[ind]);
        ind++;
        int i;
        for (i=s;i<=e;i++) {
            if (inorder[i]==pre[ind-1]) break;
        }
        root->left=helper(pre,inorder,s,i-1);
        root->right=helper(pre,inorder,i+1,e);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder,inorder,0,preorder.size()-1);
    }
};
