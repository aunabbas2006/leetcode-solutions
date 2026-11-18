// Problem: Minimum Number of Changes to Make Binary String Beautiful
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/
// Approach: Iterate through the string in steps of two, counting how many adjacent character pairs `(s[2i], s[2i+1])` contain different characters.

class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int changes = 0;
        for (int i = 0; i < n; i += 2) {
            if (s[i] != s[i+1]) {
                changes++;
            }
        }
        return changes;
    }
};
