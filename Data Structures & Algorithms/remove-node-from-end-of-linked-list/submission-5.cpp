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
        ListNode dummy(0, head);
        ListNode *first = head;
        while(n)
        {
            n--;
            first = first->next;
        }

        ListNode *second = &dummy;
        while(first)
        {
            first = first -> next;
            second = second -> next;
        }
        second->next = second->next -> next;
        return dummy.next;
    }
};
