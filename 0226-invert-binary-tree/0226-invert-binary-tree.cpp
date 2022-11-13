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
        TreeNode* invert(TreeNode* root){
        if(root==NULL)
            return NULL;
        if(!root->left && !root->right)
            return root;

        TreeNode* left=invert(root->left);
        TreeNode* right=invert(root->right);
        root->left=right;
        root->right=left;
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        return invert(root);
    }
};