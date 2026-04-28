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
    ListNode *getKth(ListNode *node, int k)
    {
        while(k and node)
        {
            node = node->next;
            k--;
        }
        return node;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *groupPrev = dummy;

        while(true)
        {
            ListNode *kth = getKth(groupPrev, k);
            if(!kth) break; //fewer than k nodes left

            ListNode *groupNext = kth->next, *prev = groupNext, *curr = groupPrev->next; //ohh prev is already pointing to the node that will be pointed to by the last node after reversal
            while(curr != groupNext)
            {
                ListNode *temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            ListNode *tmp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = tmp; 
        }
        return dummy->next;
    }
};
