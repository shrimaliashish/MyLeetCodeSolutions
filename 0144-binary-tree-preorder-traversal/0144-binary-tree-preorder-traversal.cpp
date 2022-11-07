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
    TreeNode* rightMost(TreeNode* root,TreeNode* cur){
        TreeNode* temp=root;
        while(temp->right && temp->right!=cur){
            temp=temp->right;
        }
        return temp;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>v;
        TreeNode* cur=root,*temp=root;
        while(cur!=NULL){
            if(cur->left==NULL){
                v.push_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode* tempRight=rightMost(cur->left,cur);
                cout<<tempRight->val<<endl;
                if(tempRight->right==NULL){
                    tempRight->right=cur;
                    v.push_back(cur->val);
                    cur=cur->left;
                }else if(tempRight->right==cur){
                    // v.push_back(tempRight->val);
                    cur=cur->right;
                    tempRight->right=NULL;
                }
                else{
                    cur=cur->left;
                }
            }
            
        }
        return v;
    }
};