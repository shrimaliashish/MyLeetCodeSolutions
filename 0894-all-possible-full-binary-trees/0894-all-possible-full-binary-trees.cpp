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
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2 ==0)  return {};
        vector<vector<TreeNode *>> dp;
        // we are creating a dp in which the for say dp[0] will repesent the ans for the stage 0
        // here I am creating a stage for every n 
//         for say:- n = 1 stage = 0
//         n = 3 stage = 1
         // Hence, here the higher stages can be derived from the lower stages 
//          for eg. when n= 5 stage will be 2 
//          so for this stage we will go on deciding the left and right of its subtree
//         from the previous stages so lets start the code
        // n= 1
        TreeNode* node = new TreeNode(0);
        dp.push_back({node});
        if(n==1)  return dp[0];
        
        TreeNode* nnode =  new TreeNode(0, new TreeNode(0),  new TreeNode(0));
        dp.push_back({nnode});
        if(n==3)   return dp[1];
        
        int sg = (n+1)/2;   // the total possible stages for the dp when n>3 
        
        for(int i=2;i<sg;i++){
            vector<TreeNode*> res;
            for(int j=0;j<i;j++){
                // now we gonna take our left for subtree the i th stage dp from the dp[j]
                // and the right subtree from the dp[i-j-1] vector 
                // because these stages refered for the no. of nodes we gonna invest on each side
                for(auto l:dp[j]){
                    for(auto r:dp[i-1-j]){
                        TreeNode *nfode = new TreeNode(0);
                        nfode->left = l;
                        nfode->right = r;
                        res.push_back(nfode);
                    }
                }
                
                
            }
            dp.push_back(res);
        }
        
        return dp[sg-1];
        
    }
};