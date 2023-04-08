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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head){
            return head;
        }
        
        ListNode* slow=head,*fast=head,*rightList,*tempHead,*temp=head;
        int n=1;
        while(temp->next){
            temp=temp->next;
            n++;
        }
        // temp->next=head;
        k=k%n;
        if(k==0)
            return head;
        while(k--){
            fast=fast->next;
        }
        while(fast && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        
        // cout<<slow->val;
        
        rightList=slow->next;
        tempHead=rightList;
        slow->next=NULL;
        while(rightList->next){
            rightList=rightList->next;
        }
        rightList->next=head;
        return tempHead;
        // return head;
    }
};