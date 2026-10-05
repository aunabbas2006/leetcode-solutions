// Problem: Score of Parentheses
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/score-of-parentheses/
// Approach: Iterate through the string, maintaining a nesting depth counter. When an opening parenthesis is encountered, increment depth; when a closing parenthesis `s[i]` immediately follows an opening one `s[i-1]`, decrement depth and add `2` raised to this new depth value to the total score.

class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        int depth = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                depth++;
            } else { 
                depth--;
                
                
                
                
                
                
                
                if (s[i-1] == '(') {
                    score += (1 << depth);
                }
            }
        }
        return score;
    }
};
