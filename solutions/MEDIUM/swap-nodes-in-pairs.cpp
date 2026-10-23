// Problem: Swap Nodes in Pairs
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/swap-nodes-in-pairs/
// Approach: Recursively swap the first two nodes of the current sublist, then link the original first node to the result of the recursive call on the remaining list, returning the original second node as the new sublist head.

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            prev->next = second;
            first->next = second->next;
            second->next = first;

            prev = first;
        }

        return dummy.next;
    }
};
