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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head,*slow,*temp;
        temp=new ListNode(0);
        temp->next=head;
        ListNode* tempHead=temp;
        slow=tempHead;
        while(n--){
            fast=fast->next;
        }
        while(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        if(slow==tempHead)
            return head->next;
        slow->next=slow->next->next;
        return head;
    }
};