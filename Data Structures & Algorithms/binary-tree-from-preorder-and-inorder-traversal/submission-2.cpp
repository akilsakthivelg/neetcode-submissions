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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,int s=INT_MIN,int e=INT_MAX) {
        if (s==INT_MIN && e==INT_MAX) {
            s=0;
            e=inorder.size()-1;
        }
        TreeNode* root = NULL;
        int i=0;
        for (i=s;i<=e;i++) {
            if (preorder[ind]==inorder[i]) {
                root=new TreeNode(preorder[ind++]);
                root->left = buildTree(preorder,inorder,s,i-1);
                root->right = buildTree(preorder,inorder,i+1,e);
                break;
            }
        }
        return root;

    }
};
