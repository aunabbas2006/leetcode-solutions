// Problem: Remove Nth Node From End of List
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Approach: Use a two-pointer approach: advance a `fast` pointer `n+1` steps ahead of a `slow` pointer, then move both pointers simultaneously until `fast` reaches the end of the list. The `slow` pointer will then be at the node preceding the one to be removed; update `slow.next` to skip the target node.

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;

        ListNode* newHead = dummy->next;
        delete dummy; 
        
        return newHead;
    }
};
