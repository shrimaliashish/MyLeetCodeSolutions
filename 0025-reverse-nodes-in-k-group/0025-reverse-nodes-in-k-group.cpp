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
    
    ListNode* reverse(ListNode* head) {
        ListNode* cur=head,*next=NULL,*prev=NULL;
        while(cur){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // return reverse(head,NULL);
        ListNode* temp=head;
        ListNode* cur,*start,*next,*prev=NULL;
        int c=1;
        while(temp){
            // cout<<temp->val<<endl;
            cur=temp;
            c=1;
            while(c<k && cur){
                cur=cur->next;
                c++;
            }
            if(!cur)
                break;
            next=cur->next?cur->next:NULL;
            cur->next=NULL;
            start=reverse(temp);
            
            if(prev==NULL){
                head=start;
                prev=head;
            }else{
                prev->next=start;
            }
            while(prev->next){
                prev=prev->next;
            }
            // cout<<"Temp: "<<temp->val<<" prev: "<<prev->val<<" cur: "<<cur->val<<" next: "<<next->val<<endl;
            // cout<<start->val<<endl;
            prev->next=next;
            temp=next;
            
            // ListNode* itr=head;
            // while(itr){
            //     cout<<itr->val<<endl;
            //     itr=itr->next;
            // }
            // cout<<endl;
            
        }
        return head;
    }
};