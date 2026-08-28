// Problem: Longest Palindromic Substring
// Difficulty: MEDIUM
// Link: https://leetcode.com/problems/longest-palindromic-substring/
// Approach: Iterate through each character and each pair of adjacent characters as potential centers, expanding outwards from each center to find the longest palindromic substring.

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n < 2) {
            return s;
        }

        int start = 0;
        int maxLength = 1;

        for (int i = 0; i < n; ++i) {
            
            int left1 = i;
            int right1 = i;
            while (left1 >= 0 && right1 < n && s[left1] == s[right1]) {
                if (right1 - left1 + 1 > maxLength) {
                    maxLength = right1 - left1 + 1;
                    start = left1;
                }
                left1--;
                right1++;
            }

            
            int left2 = i;
            int right2 = i + 1;
            while (left2 >= 0 && right2 < n && s[left2] == s[right2]) {
                if (right2 - left2 + 1 > maxLength) {
                    maxLength = right2 - left2 + 1;
                    start = left2;
                }
                left2--;
                right2++;
            }
        }

        return s.substr(start, maxLength);
    }
};
