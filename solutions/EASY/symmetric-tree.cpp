// Problem: Symmetric Tree
// Difficulty: EASY
// Link: https://leetcode.com/problems/symmetric-tree/
// Approach: Use a recursive helper function to simultaneously traverse and compare nodes from the left and right subtrees in a mirror-image fashion. Alternatively, an iterative approach can use a queue to store pairs of nodes for comparison.

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }

private:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) {
            return true;
        }
        if (!t1 || !t2) {
            return false;
        }
        if (t1->val != t2->val) {
            return false;
        }

        return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }
};
