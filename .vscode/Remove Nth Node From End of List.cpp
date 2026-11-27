
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast n steps ahead
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the last node
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Unlink and delete the target node
        ListNode* target = slow->next;
        slow->next = target->next;
        delete target;

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};