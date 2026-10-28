// Problem: Path Sum
// Difficulty: EASY
// Link: https://leetcode.com/problems/path-sum/
// Approach: Depth-First Search (DFS) recursively traverses the tree, subtracting node values from the target sum, and returns true if a leaf node is reached with a remaining sum of zero.

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        targetSum -= root->val;

        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == 0;
        }

        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};
