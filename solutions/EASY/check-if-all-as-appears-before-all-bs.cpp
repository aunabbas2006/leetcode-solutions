// Problem: Check if All A's Appears Before All B's
// Difficulty: EASY
// Link: https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/
// Approach: Iterate through the string, keeping a flag for whether a 'b' has been encountered. If an 'a' is encountered after the flag indicates a 'b' has already appeared, return false. Otherwise, if the loop completes, return true.

class Solution {
public:
    bool checkString(string s) {
        bool b_seen = false;
        for (char c : s) {
            if (c == 'b') {
                b_seen = true;
            } else { 
                if (b_seen) {
                    return false;
                }
            }
        }
        return true;
    }
};
