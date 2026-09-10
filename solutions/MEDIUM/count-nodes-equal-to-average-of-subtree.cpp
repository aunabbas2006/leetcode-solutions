// Problem: Count Nodes Equal to Average of Subtree
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
// Approach: Perform a post-order traversal (DFS) that recursively returns the sum and count of nodes for each subtree. At each node, use these aggregated values to compute the subtree average, compare it with the node's value, and increment a global counter if they match.

class Solution {
private:
    
    
    
    
    pair<int, int> calculateSubtreeStats(TreeNode* node, int& count_nodes_equal_to_avg) {
        if (node == nullptr) {
            return {0, 0};
        }

        
        pair<int, int> left_subtree_info = calculateSubtreeStats(node->left, count_nodes_equal_to_avg);
        pair<int, int> right_subtree_info = calculateSubtreeStats(node->right, count_nodes_equal_to_avg);

        
        int current_subtree_sum = left_subtree_info.first + right_subtree_info.first + node->val;
        int current_subtree_count = left_subtree_info.second + right_subtree_info.second + 1;

        
        if (node->val == (current_subtree_sum / current_subtree_count)) {
            count_nodes_equal_to_avg++;
        }

        
        return {current_subtree_sum, current_subtree_count};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        int result_count = 0; 
        calculateSubtreeStats(root, result_count);
        return result_count;
    }
};
