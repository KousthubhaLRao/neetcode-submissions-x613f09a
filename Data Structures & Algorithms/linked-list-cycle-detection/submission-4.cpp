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
    bool hasCycle(ListNode* head) {
        ListNode *head1 = head;
        bool flag = false;
        if(head == NULL) return false;

        while(head1 != NULL)
        {
            head = head->next;
            if(head1->next == NULL) break;
            head1 = head1->next->next;
            if(head == head1)
            {
                flag = true;
                break;
            }
        }
        return flag;
    }
};
