/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return NULL;
        ListNode *slowPointer = head, *fastPointer = head;
 
        while (slowPointer != NULL && fastPointer != NULL
               && fastPointer->next != NULL) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
            if (slowPointer == fastPointer)
                break;
        }
 
        // if no loop exists
        if (slowPointer != fastPointer)
            return NULL;
 
        // reset slow pointer to head
        // and traverse again
        slowPointer = head;
        while (slowPointer != fastPointer) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next;
        }
 
        return slowPointer;
    }
};