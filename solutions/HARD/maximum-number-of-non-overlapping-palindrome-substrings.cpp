// Problem: Maximum Number of Non-overlapping Palindrome Substrings
// Difficulty: HARD
// Link: https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/
// Approach: A two-stage dynamic programming approach where the first stage identifies all palindrome substrings and the second stage maximizes the count of non-overlapping valid palindromes of length at least `k`.

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();

        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

        for (int i = 0; i < n; ++i) {
            isPalindrome[i][i] = true;
        }

        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i+1]) {
                isPalindrome[i][i+1] = true;
            }
        }

        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && isPalindrome[i+1][j-1]) {
                    isPalindrome[i][j] = true;
                }
            }
        }

        vector<int> dp(n, 0);

        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                dp[i] = dp[i-1];
            }

            for (int j = 0; j <= i; ++j) {
                if (isPalindrome[j][i] && (i - j + 1 >= k)) {
                    int prev_palindromes_count = 0;
                    if (j > 0) {
                        prev_palindromes_count = dp[j-1];
                    }
                    dp[i] = max(dp[i], prev_palindromes_count + 1);
                }
            }
        }

        return dp[n-1];
    }
};
