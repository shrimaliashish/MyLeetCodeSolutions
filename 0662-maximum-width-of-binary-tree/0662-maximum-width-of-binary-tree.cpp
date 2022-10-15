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
    
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long int>>q;
        q.push({root,1});
        long long int mx=0;
        while(!q.empty()){
            int sz=q.size();
            vector<pair<TreeNode*,long long int>>v;
            int mn=q.front().second;
            for(int i=0;i<sz;i++){
                pair<TreeNode*,int>p=q.front();
                TreeNode* temp=q.front().first;
                long long int j=p.second-mn;
                if(temp==root)
                    j=1;
                q.pop();
                v.push_back(p);
                if(temp->left)
                    q.push({temp->left,j*2});
                 if(temp->right)
                    q.push({temp->right,j*2+1});
            }

            mx=max(v[sz-1].second-v[0].second+1,mx);
        }
        return mx;
    }
};