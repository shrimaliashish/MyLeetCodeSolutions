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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int lvl=0;
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int sz=q.size();
                vector<int>v;
            for(int i=0;i<sz;i++){
                TreeNode* temp=q.front();
                q.pop();
                v.push_back(temp->val);
                if(lvl%2){
                    
                    if(temp->right)
                        q.push(temp->right);
                    if(temp->left)
                        q.push(temp->left);
                        
                }
                else{
                    
                    if(temp->left)
                        q.push(temp->left);
                    if(temp->right)
                        q.push(temp->right);
                        
                }
            } 
            ans.push_back(v);
        }
        return ans;
    }
};