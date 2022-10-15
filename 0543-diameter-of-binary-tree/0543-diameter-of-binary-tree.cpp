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
        int left=height(node->left);
        int right=height(node->right);
        mx=max(right+left-1,mx);
        dfs(node->left);
        dfs(node->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
            dfs(root);
        return mx+1;
    }
};