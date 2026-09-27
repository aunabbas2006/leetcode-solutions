// Problem: Reverse Substrings Between Each Pair of Parentheses
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
// Approach: Use a stack to manage string segments: push the current accumulated string onto the stack when an opening parenthesis is encountered, and upon a closing parenthesis, reverse the current segment and append it to the string popped from the stack.

class Solution {
public:
    string reverseParentheses(string s) {
        vector<string> stack;
        string current_segment;

        for (char c : s) {
            if (c == '(') {
                
                
                stack.push_back(current_segment);
                current_segment = "";
            } else if (c == ')') {
                
                
                
                reverse(current_segment.begin(), current_segment.end());
                current_segment = stack.back() + current_segment;
                stack.pop_back();
            } else {
                
                current_segment += c;
            }
        }
        
        
        return current_segment;
    }
};
