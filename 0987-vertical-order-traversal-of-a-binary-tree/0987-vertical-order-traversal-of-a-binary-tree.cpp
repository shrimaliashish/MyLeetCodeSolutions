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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
     map<int,vector<int>>m,m2;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* temp=q.front().first;
                int level=q.front().second;
                q.pop();
                m2[level].push_back(temp->val);
                if(temp->left)
                q.push({temp->left,level-1});
                if(temp->right)
                q.push({temp->right,level+1});
            }
            for(auto x:m2){
                sort(x.second.begin(),x.second.end());
                for(auto y:x.second){
                    m[x.first].push_back(y);
                }
            }
            m2.clear();
        }
        vector<vector<int>>v;
        for(auto x:m){
            v.push_back(x.second);
        }
        return v;   
    }
};