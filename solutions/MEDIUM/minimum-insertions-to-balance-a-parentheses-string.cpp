// Problem: Minimum Insertions to Balance a Parentheses String
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
// Approach: A greedy approach using two counters: one for tracking unmatched open parentheses expecting `))`, and another for accumulating insertions by ensuring each `)` is part of a `))` pair and each `(` is eventually matched.

class Solution {
public:
    int minInsertions(string s) {
        int open_count = 0;
        int insertions = 0;
        int i = 0;
        int n = s.length();

        while (i < n) {
            if (s[i] == '(') {
                open_count++;
                i++;
            } else {
                if (i + 1 < n && s[i+1] == ')') {
                    if (open_count > 0) {
                        open_count--;
                    } else {
                        insertions++;
                    }
                    i += 2;
                } else {
                    insertions++;
                    if (open_count > 0) {
                        open_count--;
                    } else {
                        insertions++;
                    }
                    i++;
                }
            }
        }

        insertions += open_count * 2;

        return insertions;
    }
};
