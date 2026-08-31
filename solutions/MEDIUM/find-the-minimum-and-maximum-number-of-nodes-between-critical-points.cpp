// Problem: Find the Minimum and Maximum Number of Nodes Between Critical Points
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
// Approach: Iterate through the linked list, tracking the current node's index and its value relative to its previous and next nodes to identify critical points. Store the indices of all critical points found, then calculate the minimum distance as the smallest difference between adjacent critical point indices and the maximum distance as the difference between the first and last critical point indices.

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        
        
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return {-1, -1};
        }

        int minDistance = INT_MAX; 
        int firstCriticalIdx = -1;
        int lastCriticalIdx = -1;
        int prevCriticalIdx = -1;

        ListNode* prevNode = head;
        ListNode* currNode = head->next;
        ListNode* nextNode = head->next->next;
        
        
        
        int currentPosition = 1; 

        
        
        while (nextNode != nullptr) {
            bool isLocalMaxima = (currNode->val > prevNode->val && currNode->val > nextNode->val);
            bool isLocalMinima = (currNode->val < prevNode->val && currNode->val < nextNode->val);

            if (isLocalMaxima || isLocalMinima) {
                if (firstCriticalIdx == -1) {
                    firstCriticalIdx = currentPosition;
                } else {
                    
                    minDistance = min(minDistance, currentPosition - prevCriticalIdx);
                }
                lastCriticalIdx = currentPosition;
                prevCriticalIdx = currentPosition; 
            }

            prevNode = currNode;
            currNode = nextNode;
            nextNode = nextNode->next;
            currentPosition++;
        }

        
        if (firstCriticalIdx == -1 || firstCriticalIdx == lastCriticalIdx) {
            return {-1, -1};
        }

        
        int maxDistance = lastCriticalIdx - firstCriticalIdx;

        return {minDistance, maxDistance};
    }
};
