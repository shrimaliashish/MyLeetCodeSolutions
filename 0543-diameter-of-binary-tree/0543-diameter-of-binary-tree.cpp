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
    int mx=INT_MIN;
    int height(TreeNode* node){
        if(!node)return 0;
        int left=height(node->left);
        int right=height(node->right);
        
        return max(left,right)+1;
    }
    void dfs(TreeNode* node){
        if(node==NULL)
            return ;
        int left=0,right=0;
        if(node->left)
        left=height(node->left);
        if(node->right)
            right=height(node->right);
        mx=max(right+left-1,mx);
        if(node->left)
            dfs(node->left);
        if(node->right)
            dfs(node->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
            dfs(root);
        return mx+1;
    }
};