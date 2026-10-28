// Problem: Binary Tree Inorder Traversal
// Difficulty: EASY
// Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Approach: Iteratively traverse the tree using a stack: repeatedly push all left children onto the stack, then pop a node, record its value, and proceed to its right child.

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* current = root;

        while (current != nullptr || !s.empty()) {
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }

            current = s.top();
            s.pop();
            result.push_back(current->val);

            current = current->right;
        }

        return result;
    }
};
