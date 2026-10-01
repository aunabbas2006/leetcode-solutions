// Problem: Valid Parentheses
// Difficulty: EASY
// Link: https://leetcode.com/problems/valid-parentheses/
// Approach: Use a stack to store opening brackets; upon encountering a closing bracket, pop from the stack and check for a match, returning false if mismatched or the stack is empty, finally ensuring the stack is empty at the end.

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else { 
                if (st.empty()) {
                    return false; 
                }
                char topChar = st.top();
                st.pop();
                
                if (c == ')' && topChar != '(') {
                    return false;
                }
                if (c == '}' && topChar != '{') {
                    return false;
                }
                if (c == ']' && topChar != '[') {
                    return false;
                }
            }
        }
        
        return st.empty();
    }
};
