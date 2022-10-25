/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* prev,ListNode* curr){
        if(curr->next==NULL){
            curr->next=prev;
            return curr;
        }
        ListNode* temp=curr->next;
        curr->next=prev;
        prev=curr;
        return reverse(prev,temp);        
    }
    
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return NULL;
        ListNode *prev=nullptr,*cur=head;
        if(cur->next==NULL){
            return cur;
        }
        return reverse(prev,cur);
        
    }
};