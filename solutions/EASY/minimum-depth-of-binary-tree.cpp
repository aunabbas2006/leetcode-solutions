// Problem: Minimum Depth of Binary Tree
// Difficulty: EASY
// Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Approach: Breadth-First Search (BFS) to traverse the tree level by level, returning the depth of the first encountered leaf node.

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;

        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left == nullptr && curr->right == nullptr) {
                    return depth;
                }

                if (curr->left != nullptr) {
                    q.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }
            depth++;
        }
        
        
        
        
        return depth; 
    }
};
