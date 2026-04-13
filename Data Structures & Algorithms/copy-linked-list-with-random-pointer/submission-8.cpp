/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }

        Node* l1 = head; 
        while (l1) {                     //this loop is to create the copies. The copies point to original's randoms
            Node* l2 = new Node(l1->val);
            l2->next = l1->random;
            l1->random = l2;
            l1 = l1->next;
        }

        Node* newHead = head->random;

        l1 = head;
        while (l1) {    //this loop is to set the random pointers of the copy the same as the original.
            Node* l2 = l1->random;        //this is possible because in the earlier loop, we made copy nodes point to original
            l2->random = (l2->next != nullptr) ? l2->next->random : nullptr;//randoms. 
            l1 = l1->next;
        }

        l1 = head;
        while (l1) { //this loop is to get back the original random pointers
            Node* l2 = l1->random;
            l1->random = l2->next;
            l2->next = (l1->next != nullptr) ? l1->next->random : nullptr;
            l1 = l1->next;
        }

        return newHead;
    }
};