// Problem: Maximum Depth of Binary Tree
// Difficulty: EASY
// Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Approach: Recursively calculate the maximum depth of the left and right subtrees, then return one plus the maximum of those two values.

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
    }
};
