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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);
        ListNode *prev = &dummy; //the dummy node
        int duplicate_left = left;
        while(left-1 > 0)
        {
            prev = prev->next; //cus i still want to be able to track the 'prev' pointer, and the thing is 1-indexed
            left--;
        }
        ListNode *original_prev = prev; //
        ListNode *cur = prev->next;
        ListNode *nex = cur;
        ListNode *end = cur; //this'll be used to connect the 1 to the 4 after the reversal.
        int len = right - duplicate_left + 1;
        while(len--)
        {
            nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }
        original_prev->next = prev;
        head = dummy.next; //head needs to point to 3
        end->next = nex; //connecting 1 to 4
        return head;
    }
};