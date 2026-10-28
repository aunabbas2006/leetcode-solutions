// Problem: Balanced Binary Tree
// Difficulty: EASY
// Link: https://leetcode.com/problems/balanced-binary-tree/
// Approach: A recursive post-order traversal that computes the height of each subtree while simultaneously checking if it is balanced, returning a sentinel value (e.g., -1) if an imbalance is found.

class Solution {
private:
    int my_max(int a, int b) {
        return a > b ? a : b;
    }

    int my_abs(int x) {
        return x < 0 ? -x : x;
    }

    int getHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = getHeight(node->left);
        if (leftHeight == -1) {
            return -1;
        }

        int rightHeight = getHeight(node->right);
        if (rightHeight == -1) {
            return -1;
        }

        if (my_abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        return 1 + my_max(leftHeight, rightHeight);
    }

public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }
};
