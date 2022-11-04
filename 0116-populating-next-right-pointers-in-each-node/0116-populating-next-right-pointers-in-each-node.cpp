/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
   vector<vector<Node*>> solve(Node* root)
    {
        vector<vector<Node*>> levelOrder;
        queue<Node*> Q;
        Q.push(root);
        
        while(!Q.empty())
        {
            int sz = Q.size();
            vector<Node*> v;
            for(int i=0;i<sz;i++){
                
                Node* node = Q.front();
                v.push_back(node);
                Q.pop();
                if(node -> left) Q.push(node->left);
                if(node->right) Q.push(node->right);
            }
            levelOrder.push_back(v);
        }
        
        return levelOrder;
        
    }
    
    Node* connect(Node* root) {
        if(root==NULL) return root;
        vector<vector<Node*>> levelOrder = solve(root);
        for(int i=0;i<levelOrder.size();i++){
            for(int j=0;j<levelOrder[i].size();j++){
                
                if(j == levelOrder[i].size()-1) {
                    levelOrder[i][j]->next = NULL;
                }
                else{
                    levelOrder[i][j]->next = levelOrder[i][j+1];
                }
            }
        }
        
        return root;
    }
};