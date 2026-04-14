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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0, NULL);  //the dummy node.
        ListNode *cur = &dummy;
        int carry = 0;

        while(l1 or l2 or carry)
        {
            int l1_digit = l1 ? l1->val : 0;
            int l2_digit = l2 ? l2->val : 0;  //read current digit of a LL. It's 0 if the list's already ended.

            int sum = l1_digit + l2_digit + carry;     //carry gets tracked separately. And when sum isn't greater than 10, carry remains 0.
            carry = sum / 10;
            sum = sum % 10; //the digit that gets stored in the result LL
            cur->next = new ListNode(sum, NULL);
            cur = cur->next;

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr; //moving through the LL for as long as it hasn't ended.
        }
        return dummy.next;
    }
};
