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
    int mx=-1e9;
    int getMax(TreeNode* root){
        if(root==NULL)
            return 0;
        int left=getMax(root->left);
        int right=getMax(root->right);
        mx=max({mx,left+root->val,right+root->val,root->val,left+right+root->val});
        
        return max({left+root->val,right+root->val,root->val});
    }
    int maxPathSum(TreeNode* root) {
        getMax(root);
        return mx;
    }
};