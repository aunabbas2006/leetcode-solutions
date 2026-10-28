// Problem: Same Tree
// Difficulty: EASY
// Link: https://leetcode.com/problems/same-tree/
// Approach: Perform a simultaneous recursive Depth-First Search (DFS) on both trees, comparing node values and structure at each corresponding level.

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if (p == nullptr || q == nullptr) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
