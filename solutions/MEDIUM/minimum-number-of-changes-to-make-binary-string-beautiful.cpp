// Problem: Minimum Number of Changes to Make Binary String Beautiful
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/
// Approach: Iterate through the string in steps of two, and for each pair of adjacent characters, increment a counter if they are different.

class Solution {
public:
    int minChanges(string s) {
        int changes = 0;
        for (int i = 0; i < s.length(); i += 2) {
            if (s[i] != s[i+1]) {
                changes++;
            }
        }
        return changes;
    }
};
