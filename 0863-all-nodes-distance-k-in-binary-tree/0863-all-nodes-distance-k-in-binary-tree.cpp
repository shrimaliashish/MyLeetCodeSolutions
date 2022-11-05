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
    map<TreeNode*,TreeNode*>m;
    void bfs(TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        m[root]=root;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left){
                    m[temp->left]=temp;
                    q.push(temp->left);
                }
                if(temp->right){
                    m[temp->right]=temp; 
                    q.push(temp->right);
                }
            }
        }
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>v;
        if(k==0){
           v.push_back(target->val);
        }
        bfs(root);
        map<TreeNode*,int>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=1;
        int c=0;
        while(!q.empty()){
            c++;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* temp=q.front();
                q.pop();
                if( temp->left && !vis.count(temp->left)){
                    q.push(temp->left);
                    vis[temp->left]=1;
                }
                if( temp->right && !vis.count(temp->right)){
                    q.push(temp->right);
                     vis[temp->right]=1;
                }
                if(!vis.count(m[temp])){
                    q.push(m[temp]);
                     vis[m[temp]]=1;
                }
            }
            if(c==k)
            {
                while(!q.empty()){
                    v.push_back(q.front()->val);
                    // cout<<"Hello"<<endl;
                    q.pop();
                }
                return v;
            }
        }
        return v;
    }
};