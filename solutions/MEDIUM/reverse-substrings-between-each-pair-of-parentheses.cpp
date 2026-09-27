// Problem: Reverse Substrings Between Each Pair of Parentheses
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
// Approach: Pre-calculate matching parenthesis pairs, then traverse the string by stepping forward or backward. When a parenthesis is encountered, jump to its matching pair and reverse the traversal direction. Append only letters to the result.

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> s_stack;
        string current_segment = "";
        
        for (char c : s) {
            if (c == '(') {
                s_stack.push(current_segment);
                current_segment = "";
            } else if (c == ')') {
                reverse(current_segment.begin(), current_segment.end());
                string prefix = s_stack.top();
                s_stack.pop();
                current_segment = prefix + current_segment;
            } else { 
                current_segment += c;
            }
        }
        
        return current_segment;
    }
};
