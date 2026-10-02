// Problem: Generate Parentheses
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/generate-parentheses/
// Approach: Recursive backtracking builds valid parenthesis strings by adding '(' only if fewer than `n` are used, and ')' only if fewer than '(' are currently open, until `n` pairs are formed.

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current_string;
        backtrack(n, 0, 0, current_string, result);
        return result;
    }

private:
    void backtrack(int n, int open, int close, string& current_string, vector<string>& result) {
        if (open == n && close == n) {
            result.push_back(current_string);
            return;
        }

        if (open < n) {
            current_string.push_back('(');
            backtrack(n, open + 1, close, current_string, result);
            current_string.pop_back();
        }

        if (close < open) {
            current_string.push_back(')');
            backtrack(n, open, close + 1, current_string, result);
            current_string.pop_back();
        }
    }
};
