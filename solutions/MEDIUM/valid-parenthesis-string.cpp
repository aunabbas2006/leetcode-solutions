// Problem: Valid Parenthesis String
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/valid-parenthesis-string/
// Approach: Iterate through the string, maintaining two counts: `low` for the minimum possible balance of open parentheses (treating '*' as ')' or empty) and `high` for the maximum possible balance (treating '*' as '('). Ensure `high` never drops below zero, and at the end of the string, `low` must be zero for validity.

class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0; 
        int maxOpen = 0; 

        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen--;
                maxOpen--;
            } else { 
                minOpen--; 
                maxOpen++; 
            }

            
            
            
            
            
            if (minOpen < 0) {
                minOpen = 0;
            }

            
            
            
            
            if (maxOpen < 0) {
                return false;
            }
        }

        
        
        
        return minOpen == 0;
    }
};
