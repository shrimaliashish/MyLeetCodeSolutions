/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *temp=head,*tempHead=NULL,*cur=NULL;
        map<Node*,pair<Node*,Node*>>mp; //node->(next,random)
        map<Node*,Node*>m;
        while(temp){
            mp[temp]={temp->next,temp->random};
            Node* newNode=new Node(temp->val);
            m[temp]=newNode;
            temp=temp->next;
        }
        temp=head;
        while(temp){
            m[temp]->next=m[mp[temp].first];
            m[temp]->random=m[mp[temp].second];
            if(!tempHead){
                tempHead=m[temp];
                cur=tempHead;
            }else{
                cur->next=m[temp];
                cur=cur->next;
            }
            temp=temp->next;
        }
        return tempHead;
    }
};