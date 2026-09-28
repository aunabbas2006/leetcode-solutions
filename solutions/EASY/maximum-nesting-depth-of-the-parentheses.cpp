// Problem: Maximum Nesting Depth of the Parentheses
// Difficulty: EASY
// Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
// Approach: Iterate through the string, incrementing a counter for each opening parenthesis and decrementing for each closing parenthesis, while tracking the maximum value reached by the counter.

class Solution {
public:
    int maxDepth(string s) {
        int current_depth = 0;
        int max_depth = 0;

        for (char c : s) {
            if (c == '(') {
                current_depth++;
                if (current_depth > max_depth) {
                    max_depth = current_depth;
                }
            } else if (c == ')') {
                current_depth--;
            }
        }

        return max_depth;
    }
};
