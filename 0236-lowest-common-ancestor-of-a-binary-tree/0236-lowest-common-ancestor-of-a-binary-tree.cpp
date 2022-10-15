/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
      if(!root)return NULL;
        root->left=dfs(root->left,p,q);
        root->right=dfs(root->right,p,q);
        if(root==p || root==q)
            return root;
        if(root->left && root->right)
            return root;
        return root->left?root->left:root->right;
            
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root,p,q);
    }
};