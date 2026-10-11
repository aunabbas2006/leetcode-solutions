// Problem: Reverse Nodes in k-Group
// Difficulty: HARD
// Link: https://leetcode.com/problems/reverse-nodes-in-k-group/
// Approach: Iteratively traverse the linked list, checking if at least `k` nodes remain for the current segment. If so, reverse the `k`-node sublist in place and connect its new head and tail to the previously processed segments; otherwise, return the current head.

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) {
            return head;
        }

        ListNode dummy_head;
        dummy_head.next = head;
        ListNode* prev_group_tail = &dummy_head; 

        while (true) {
            ListNode* curr_group_head = prev_group_tail->next;
            ListNode* check_ptr = curr_group_head;
            int count = 0;
            while (check_ptr && count < k) {
                check_ptr = check_ptr->next;
                count++;
            }

            if (count < k) { 
                break;
            }

            ListNode* prev = prev_group_tail; 
            ListNode* curr = curr_group_head;
            ListNode* next_node = nullptr;

            for (int i = 0; i < k; ++i) {
                next_node = curr->next; 
                curr->next = prev;      
                prev = curr;            
                curr = next_node;       
            }

            ListNode* temp_original_curr_group_head = prev_group_tail->next; 
            prev_group_tail->next = prev; 
            temp_original_curr_group_head->next = curr;

            prev_group_tail = temp_original_curr_group_head;
        }

        return dummy_head.next;
    }
};
